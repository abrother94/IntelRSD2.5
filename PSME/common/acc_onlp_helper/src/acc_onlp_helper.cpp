#include "acc_onlp_helper/acc_onlp_helper.hpp"
#include "acc_net_helper/acc_net_helper.hpp"
#include "acc_onlp_helper/asxvolt16.hpp"
#include "acc_onlp_helper/asgvolt64.hpp"
#include "acc_onlp_helper/as5916_54xks.hpp"
#include "acc_onlp_helper/as5916_54xk.hpp"

using namespace acc_onlp_helper;
using namespace acc_net_helper;

/*Fon onlp*/
#ifdef __cplusplus
extern "C"
{
#include <onlp/onlp.h>
#include <onlp/oids.h>
#include <unistd.h>
#include <onlp/sys.h>
#include <AIM/aim_log_handler.h>
#include <syslog.h>
#include <onlp/platformi/sysi.h>
#include <onlp/platformi/sfpi.h>
#include <onlp/sfp.h>
#include <onlp/fan.h>
#include <onlp/thermal.h>
#include <onlp/sys.h>
#include <onlp/psu.h>
#include <onlplib/mmap.h>
#include <AIM/aim.h>
}
#endif

#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <dirent.h>
#include <string.h>
#include <chrono>
#include <ctime>

namespace acc_onlp_helper
{
signed long get_value_from_pointer(signed char *ptr, int size);
unsigned long get_value_from_pointer_u(unsigned char *ptr, int size);

int Acc_Switch::m_fan_max_num = 0;
int Acc_Switch::m_port_max_num = 0;
int Acc_Switch::m_thermal_sen_max_num = 0;
int Acc_Switch::m_psu_max_num = 0;
int Acc_Switch::m_max_cpu_num = 0;

#define UNUSED(x) (void)(x)

static int iterate_oids_callback__(onlp_oid_t oid, void *cookie)
{
    int type = ONLP_OID_TYPE_GET(oid);
    int id = ONLP_OID_ID_GET(oid);

    static int thermal = 1;
    static int fan = 1;
    static int psu = 1;
    UNUSED(cookie);

    switch (type)
    {
    case ONLP_OID_TYPE_THERMAL:
        printf("thermal,Thermal %d,%d\n", id, thermal++);
        Acc_Switch::increase_thermal_num();
        break;
    case ONLP_OID_TYPE_FAN:
        printf("fan,Fan %d,%d\n", id, fan++);
        Acc_Switch::increase_fan_num();
        break;
    case ONLP_OID_TYPE_PSU:
        printf("psu,PSU %d,%d\n", id, psu++);
        Acc_Switch::increase_psu_num();
        break;
    default:
        printf("non[%d] \r\n", type);
        break;
    }
    return 0;
}

signed long get_value_from_pointer(signed char *ptr, int size)
{
    signed long sum = 0;
    signed char i;

    if (size > 4)
        return (sum);

    for (i = 0; i < size; ++i)
    {
        sum = sum * 256 + (*(ptr + i));
    }

    return (sum);
}

unsigned long get_value_from_pointer_u(unsigned char *ptr, int size)
{
    try
    {
        unsigned long sum = 0;
        unsigned char i;

        if (size > 4)
            return (sum);

        for (i = 0; i < size; ++i)
        {
            sum = sum * 256 + (*(ptr + i));
        }

        return (sum);
    }
    catch (const exception &e)
    {
        printf("get_value_from_pointer_u error\r\n");
        return 0;
    }
}

float e_oom::get_value(std::string attri_name)
{
    try
    {
        Json::Value Att_Json = m_std["Attributes"];
        Json::Value _Json = get_attri_by_name(attri_name, Att_Json);

        float tmp_unit = 0;
        int tmp_base = _Json[attri_name]["Byte_Address"].asInt();
        //printf("get_status [%s] base offset[%d]\r\n",attri_name.c_str(), tmp_base);
        int tmp_size = _Json[attri_name]["Size"].asInt();
        //printf("get_status  Size[%d]\r\n", tmp_size);
        tmp_unit = _Json[attri_name]["unit"].asFloat();
        //printf("get_status  tmp_unit[%f]\r\n", tmp_unit);

        signed char tmp_PN[4] = {0};
        memcpy(tmp_PN, m_eeprom + tmp_base, tmp_size);
        signed long e_value = get_value_from_pointer(tmp_PN, tmp_size);

        //printf("get_value [%d] \r\n", e_value);
        //printf("get_value return [%f]\r\n", e_value * tmp_unit);

        return (e_value * tmp_unit);
    }
    catch (const exception &e)
    {
        printf("get_value error\r\n");
        return 0;
    }
}

float e_oom::get_value_u(std::string attri_name)
{
    try
    {
        Json::Value Att_Json = m_std["Attributes"];
        Json::Value _Json = get_attri_by_name(attri_name, Att_Json);

        float tmp_unit = 0;
        int tmp_base = _Json[attri_name]["Byte_Address"].asInt();
        //printf("get_status_u [%s] base offset[%d]\r\n",attri_name.c_str(), tmp_base);
        int tmp_size = _Json[attri_name]["Size"].asInt();
        //printf("get_status_u  Size[%d]\r\n", tmp_size);
        tmp_unit = _Json[attri_name]["unit"].asFloat();
        //printf("get_status_u  tmp_unit[%f]\r\n", tmp_unit);

        unsigned char tmp_PN[4] = {0};
        memcpy(tmp_PN, m_eeprom + tmp_base, tmp_size);
        unsigned long e_value = get_value_from_pointer_u(tmp_PN, tmp_size);

        //printf("get_value_u [%u] \r\n", e_value);
        //printf("get_value_u return [%f] \r\n", e_value * tmp_unit);

        return (e_value * tmp_unit);
    }
    catch (const exception &e)
    {
        printf("get_value_u error\r\n");
        return 0;
    }
}

std::string e_oom::get_value_s(std::string attri_name)
{
    try
    {
        std::string ret_attri = {};
        unsigned char tmp_value[32] = {0};

        Json::Value Att_Json = m_std["Attributes"];
        Json::Value _Json = get_attri_by_name(attri_name, Att_Json);

        int tmp_base = _Json[attri_name]["Byte_Address"].asInt();
        //printf("get_status_s [%s] base offset[%d]\r\n",attri_name.c_str(), tmp_base);
        int tmp_size = _Json[attri_name]["Size"].asInt();
        //printf("get_status_s  Size[%d]\r\n", tmp_size);

        if (tmp_size < (int)sizeof(tmp_value))
        {
            memcpy(tmp_value, m_eeprom + tmp_base, tmp_size);
            ret_attri = (char *)tmp_value;
            ret_attri.erase(remove(ret_attri.begin(), ret_attri.end(), ' '), ret_attri.end());
        }

        return ret_attri;
    }
    catch (const exception &e)
    {
        printf("get_value_s error\r\n");
        return 0;
    }
}

void e_oom::refresh_vendor_info()
{
    try
    {
        /*vendor_info Begin:*/
        std::string ff;
        /* get SFP Vendor Name */
        if (m_current_status["SFP Vendor Name"] == "NA")
        {
            ff = get_value_s("Vendor_name");
            m_current_status["SFP Vendor Name"] = ff;
        }

        /* get Part Number */
        if (m_current_status["Part Number"] == "NA")
        {
            ff = get_value_s("Vendor_PN");
            m_current_status["Part Number"] = ff;
        }

        /* get Serial Number */
        if (m_current_status["Serial Number"] == "NA")
        {
            ff = get_value_s("Vendor_SN");
            m_current_status["Serial Number"] = ff;
        }

        /* get Manufacture Date */
        if (m_current_status["Manufacture Date"] == "NA")
        {
            ff = get_value_s("Data_Code");
            m_current_status["Manufacture Date"] = ff;
        }
        /*vendor_info End  :*/
    }
    catch (const exception &e)
    {
        printf("refresh_vendor_info error\r\n");
        return;
    }
}

void e_oom::default_vendor_info()
{
    /*vendor_info Begin:*/
    m_current_status["SFP Vendor Name"] = "NA";
    m_current_status["Part Number"] = "NA";
    m_current_status["Serial Number"] = "NA";
    m_current_status["Manufacture Date"] = "NA";
    /*vendor_info End  :*/
}

void e_oom::refresh_temp()
{
    try
    {
        /*Temperature Begin:*/
        float ff;
        /* get Temp_High_Alarm */
        if (m_current_status["Temperature"]["UpperThresholdFatal"] == 0)
        {
            ff = get_value("Temp_High_Alarm");
            m_current_status["Temperature"]["UpperThresholdFatal"] = FF3(ff);
        }

        /* get Temp_Low_Alarm */
        if (m_current_status["Temperature"]["LowerThresholdFatal"] == 0)
        {
            ff = get_value("Temp_Low_Alarm");
            m_current_status["Temperature"]["LowerThresholdFatal"] = FF3(ff);
        }

        /* get Temp_High_Warning */
        if (m_current_status["Temperature"]["UpperThresholdCritical"] == 0)
        {
            ff = get_value("Temp_High_Warning");
            m_current_status["Temperature"]["UpperThresholdCritical"] = FF3(ff);
        }

        /* get Temp_Low_Warning */
        if (m_current_status["Temperature"]["LowerThresholdCritical"] == 0)
        {
            ff = get_value("Temp_Low_Warning");
            m_current_status["Temperature"]["LowerThresholdCritical"] = FF3(ff);
        }

        /* get Temperature */
        ff = get_value("Temperature");
        m_current_status["Temperature"]["Reading"] = FF3(ff);

        /*
    
               Critical
    
           UpperThresholdFatal >=
    
               Warning
    
           UpperThresholdCritical >=
    
               OK
    
           LowerrThresholdCritical >=
          
               Warning
    
           LowerThresholdFatal >=
    
               Critical
    */
        if (((FF3(ff) >= m_current_status["Temperature"]["UpperThresholdCritical"]) && (FF3(ff) < m_current_status["Temperature"]["UpperThresholdFatal"])) || ((FF3(ff) >= m_current_status["Temperature"]["LowerThresholdFatal"]) && (FF3(ff) < m_current_status["Temperature"]["LowerThresholdCritical"])))
        {
            m_current_status["Temperature"]["Status"]["Health"] = "Warning";
            m_current_status["Temperature"]["Status"]["State"] = "Enabled";
        }
        else if ((FF3(ff) >= m_current_status["Temperature"]["UpperThresholdFatal"]) || (FF3(ff) < m_current_status["Temperature"]["LowerThresholdFatal"]))
        {
            m_current_status["Temperature"]["Status"]["Health"] = "Critical";
            m_current_status["Temperature"]["Status"]["State"] = "Enabled";
        }
        else
        {
            m_current_status["Temperature"]["Status"]["Health"] = "OK";
            m_current_status["Temperature"]["Status"]["State"] = "Enabled";
        }
        /*Temperature End  :*/
    }
    catch (const exception &e)
    {
        printf("refresh_temp error\r\n");
        return;
    }
}

void e_oom::default_temp()
{
    /*Temperature Begin:*/
    m_current_status["Temperature"]["UpperThresholdFatal"] = 0;
    m_current_status["Temperature"]["LowerThresholdFatal"] = 0;
    m_current_status["Temperature"]["UpperThresholdCritical"] = 0;
    m_current_status["Temperature"]["LowerThresholdCritical"] = 0;
    m_current_status["Temperature"]["Reading"] = 0;
    m_current_status["Temperature"]["Status"]["Health"] = json::Value::Type::NIL;
    m_current_status["Temperature"]["Status"]["State"] = json::Value::Type::NIL;
    /*Temperature End  :*/
}

void e_oom::refresh_voltage()
{
    try
    {
        /*Voltage Begin:*/
        double ff;
        /* get Voltage_High_Alarm */
        if (m_current_status["Voltage"]["UpperThresholdFatal"] == 0)
        {
            ff = get_value_u("Voltage_High_Alarm");
            m_current_status["Voltage"]["UpperThresholdFatal"] = FF3(ff);
        }

        /* get Voltage_Low_Alarm */
        if (m_current_status["Voltage"]["LowerThresholdFatal"] == 0)
        {
            ff = get_value_u("Voltage_Low_Alarm");
            m_current_status["Voltage"]["LowerThresholdFatal"] = FF3(ff);
        }

        /* get Voltage_High_Warning */
        if (m_current_status["Voltage"]["UpperThresholdCritical"] == 0)
        {
            ff = get_value_u("Voltage_High_Warning");
            m_current_status["Voltage"]["UpperThresholdCritical"] = FF3(ff);
        }

        /* get Voltage_Low_Warning */
        if (m_current_status["Voltage"]["LowerThresholdCritical"] == 0)
        {
            ff = get_value_u("Voltage_Low_Warning");
            m_current_status["Voltage"]["LowerThresholdCritical"] = FF3(ff);
        }

        /* get Voltage */
        ff = get_value_u("Voltage");
        m_current_status["Voltage"]["Reading"] = FF3(ff);

        /*
    
               Critical
    
           UpperThresholdFatal 
    
               Warning
    
           UpperThresholdCritical 
    
               OK
    
           LowerThresholdCritical 
          
               Warning
    
           LowerThresholdFatal 
    
               Critical
    */

        if (((FF3(ff) >= m_current_status["Voltage"]["UpperThresholdCritical"]) && (FF3(ff) < m_current_status["Voltage"]["UpperThresholdFatal"])) || ((FF3(ff) >= m_current_status["Temperature"]["LowerThresholdFatal"]) && (FF3(ff) < m_current_status["Temperature"]["LowerThresholdCritical"])))
        {
            m_current_status["Voltage"]["Status"]["Health"] = "Warning";
            m_current_status["Voltage"]["Status"]["State"] = "Enabled";
        }
        else if ((FF3(ff) >= m_current_status["Voltage"]["UpperThresholdFatal"]) || (FF3(ff) < m_current_status["Voltage"]["LowerThresholdFatal"]))
        {
            m_current_status["Voltage"]["Status"]["Health"] = "Critical";
            m_current_status["Voltage"]["Status"]["State"] = "Enabled";
        }
        else
        {
            m_current_status["Voltage"]["Status"]["Health"] = "OK";
            m_current_status["Voltage"]["Status"]["State"] = "Enabled";
        }
        /*Voltage End  :*/
    }
    catch (const exception &e)
    {
        printf("refresh_voltage error\r\n");
        return;
    }
}

void e_oom::default_voltage()
{
    /*Voltage Begin:*/
    m_current_status["Voltage"]["UpperThresholdFatal"] = 0;
    m_current_status["Voltage"]["LowerThresholdFatal"] = 0;
    m_current_status["Voltage"]["UpperThresholdCritical"] = 0;
    m_current_status["Voltage"]["LowerThresholdCritical"] = 0;
    m_current_status["Voltage"]["Reading"] = 0;
    m_current_status["Voltage"]["Status"]["Health"] = json::Value::Type::NIL;
    m_current_status["Voltage"]["Status"]["State"] = json::Value::Type::NIL;
    /*Voltage End  :*/
}

void e_oom::refresh_bias()
{
    try
    {
        float ff;
        /*BiasCurrent Begin  :*/
        /* get Bias_High_Alarm */
        if (m_current_status["BiasCurrent"]["UpperThresholdFatal"] == 0)
        {
            ff = get_value_u("Bias_High_Alarm");
            m_current_status["BiasCurrent"]["UpperThresholdFatal"] = FF3(ff);
        }

        /* get Bias_Low_Alarm */
        if (m_current_status["BiasCurrent"]["LowerThresholdFatal"] == 0)
        {
            ff = get_value_u("Bias_Low_Alarm");
            m_current_status["BiasCurrent"]["LowerThresholdFatal"] = FF3(ff);
        }

        /* get Bias_High_Warning */
        if (m_current_status["BiasCurrent"]["UpperThresholdCritical"] == 0)
        {
            ff = get_value_u("Bias_High_Warning");
            m_current_status["BiasCurrent"]["UpperThresholdCritical"] = FF3(ff);
        }

        /* get Bias_Low_Warning */
        if (m_current_status["BiasCurrent"]["LowerThresholdCritical"] == 0)
        {
            ff = get_value_u("Bias_Low_Warning");
            m_current_status["BiasCurrent"]["LowerThresholdCritical"] = FF3(ff);
        }

        /* get Bias */
        ff = get_value_u("Tx_Bias");
        m_current_status["BiasCurrent"]["Reading"] = FF3(ff);
        /*
    
               Critical
    
           UpperThresholdFatal >=
    
               Warning
    
           UpperThresholdCritical >=
    
               OK
    
           LowerThresholdCritical >=
          
               Warning
    
           LowerThresholdFatal >=
    
               Critical
    */
        if (((FF3(ff) >= m_current_status["BiasCurrent"]["UpperThresholdCritical"]) && (FF3(ff) < m_current_status["BiasCurrent"]["UpperThresholdFatal"])) || ((FF3(ff) >= m_current_status["BiasCurrent"]["LowerThresholdFatal"]) && (FF3(ff) < m_current_status["BiasCurrent"]["LowerThresholdCritical"])))
        {
            m_current_status["BiasCurrent"]["Status"]["Health"] = "Warning";
            m_current_status["BiasCurrent"]["Status"]["State"] = "Enabled";
        }
        else if ((FF3(ff) >= m_current_status["BiasCurrent"]["UpperThresholdFatal"]) || (FF3(ff) < m_current_status["BiasCurrent"]["LowerThresholdFatal"]))
        {
            m_current_status["BiasCurrent"]["Status"]["Health"] = "Critical";
            m_current_status["BiasCurrent"]["Status"]["State"] = "Enabled";
        }
        else
        {
            m_current_status["BiasCurrent"]["Status"]["Health"] = "OK";
            m_current_status["BiasCurrent"]["Status"]["State"] = "Enabled";
        }
        /*BiasCurrent End    :*/
    }
    catch (const exception &e)
    {
        printf("refresh_bias error\r\n");
        return;
    }
}

void e_oom::default_bias()
{
    /*BiasCurrent Begin  :*/
    m_current_status["BiasCurrent"]["UpperThresholdFatal"] = 0;
    m_current_status["BiasCurrent"]["LowerThresholdFatal"] = 0;
    m_current_status["BiasCurrent"]["UpperThresholdCritical"] = 0;
    m_current_status["BiasCurrent"]["LowerThresholdCritical"] = 0;
    m_current_status["BiasCurrent"]["Reading"] = 0;
    m_current_status["BiasCurrent"]["Status"]["Health"] = json::Value::Type::NIL;
    m_current_status["BiasCurrent"]["Status"]["State"] = json::Value::Type::NIL;

    /*BiasCurrent End    :*/
}

void e_oom::refresh_tx_pwr()
{
    try
    {
        /*TxPower Current Begin    :*/
        float ff;
        /* get TX_Power_High_Alarm */

        if (m_current_status["TxPower"]["UpperThresholdFatal"] == 0)
        {
            ff = get_value_u("TX_Power_High_Alarm");
            m_current_status["TxPower"]["UpperThresholdFatal"] = FF3(ff);
        }

        /* get TX_Power_Low_Alarm */
        if (m_current_status["TxPower"]["LowerThresholdFatal"] == 0)
        {
            ff = get_value_u("TX_Power_Low_Alarm");
            m_current_status["TxPower"]["LowerThresholdFatal"] = FF3(ff);
        }

        /* get TX_Power_High_Warning */
        if (m_current_status["TxPower"]["UpperThresholdCritical"] == 0)
        {
            ff = get_value_u("TX_Power_High_Warning");
            m_current_status["TxPower"]["UpperThresholdCritical"] = FF3(ff);
        }

        /* get TX_Power_Low_Warning */
        if (m_current_status["TxPower"]["LowerThresholdCritical"] == 0)
        {
            ff = get_value_u("TX_Power_Low_Warning");
            m_current_status["TxPower"]["LowerThresholdCritical"] = FF3(ff);
        }

        /* get Tx_Power */
        ff = get_value_u("Tx_Power");
        m_current_status["TxPower"]["Reading"] = FF3(ff);

        /*
    
               Critical
    
           UpperThresholdFatal 
    
               Warning
    
           UpperThresholdCritical 
    
               OK
    
           LowerThresholdCritical 
          
               Warning
    
           LowerThresholdFatal 
    
               Critical
    */

        if (((FF3(ff) >= m_current_status["TxPower"]["UpperThresholdCritical"]) && (FF3(ff) < m_current_status["TxPower"]["UpperThresholdFatal"])) || ((FF3(ff) >= m_current_status["TxPower"]["LowerThresholdFatal"]) && (FF3(ff) < m_current_status["TxPower"]["LowerThresholdCritical"])))
        {
            m_current_status["TxPower"]["Status"]["Health"] = "Warning";
            m_current_status["TxPower"]["Status"]["State"] = "Enabled";
        }
        else if ((FF3(ff) >= m_current_status["TxPower"]["UpperThresholdFatal"]) || (FF3(ff) < m_current_status["TxPower"]["LowerThresholdFatal"]))
        {
            m_current_status["TxPower"]["Status"]["Health"] = "Critical";
            m_current_status["TxPower"]["Status"]["State"] = "Enabled";
        }
        else
        {
            m_current_status["TxPower"]["Status"]["Health"] = "OK";
            m_current_status["TxPower"]["Status"]["State"] = "Enabled";
        }
        /*TxPower Current End      :*/
    }
    catch (const exception &e)
    {
        printf("refresh_tx_pwr error\r\n");
        return;
    }
}

void e_oom::default_tx_pwr()
{
    /*TxPower Current Begin    :*/
    m_current_status["TxPower"]["UpperThresholdFatal"] = 0;
    m_current_status["TxPower"]["LowerThresholdFatal"] = 0;
    m_current_status["TxPower"]["UpperThresholdCritical"] = 0;
    m_current_status["TxPower"]["LowerThresholdCritical"] = 0;
    m_current_status["TxPower"]["Reading"] = 0;
    m_current_status["TxPower"]["Status"]["Health"] = json::Value::Type::NIL;
    m_current_status["TxPower"]["Status"]["State"] = json::Value::Type::NIL;
    /*TxPower Current End      :*/
}

void e_oom::refresh_rx_pwr()
{
    try
    {
        /*RxPower Current Begin      :*/
        float ff;
        /* get RX_Power_High_Alarm */
        if (m_current_status["RxPower"]["UpperThresholdFatal"] == 0)
        {
            ff = get_value("RX_Power_High_Alarm");
            m_current_status["RxPower"]["UpperThresholdFatal"] = FF3(ff);
        }

        /* get RX_Power_Low_Alarm */
        if (m_current_status["RxPower"]["LowerThresholdFatal"] == 0)
        {
            ff = get_value("RX_Power_Low_Alarm");
            m_current_status["RxPower"]["LowerThresholdFatal"] = FF3(ff);
        }

        /* get RX_Power_High_Warning */
        if (m_current_status["RxPower"]["UpperThresholdCritical"] == 0)
        {
            ff = get_value("RX_Power_High_Warning");
            m_current_status["RxPower"]["UpperThresholdCritical"] = FF3(ff);
        }

        /* get RX_Power_Low_Warning */
        if (m_current_status["RxPower"]["LowerThresholdCritical"] == 0)
        {
            ff = get_value("RX_Power_Low_Warning");
            m_current_status["RxPower"]["LowerThresholdCritical"] = FF3(ff);
        }

        /* get Rx_Power */
        ff = get_value("Rx_Power");
        m_current_status["RxPower"]["Reading"] = FF3(ff);

        /*
    
               Critical
    
           UpperThresholdFatal >=
    
               Warning
    
           UpperThresholdCritical >=
    
               OK
    
           LowerThresholdCritical >=
          
               Warning
    
           LowerThresholdFatal >=
    
               Critical
    */
        if (((FF3(ff) >= m_current_status["RxPower"]["UpperThresholdCritical"]) && (FF3(ff) < m_current_status["RxPower"]["UpperThresholdFatal"])) || ((FF3(ff) >= m_current_status["RxPower"]["LowerThresholdFatal"]) && (FF3(ff) < m_current_status["RxPower"]["LowerThresholdCritical"])))
        {
            m_current_status["RxPower"]["Status"]["Health"] = "Warning";
            m_current_status["RxPower"]["Status"]["State"] = "Enabled";
        }
        else if ((FF3(ff) >= m_current_status["RxPower"]["UpperThresholdFatal"]) || (FF3(ff) < m_current_status["RxPower"]["LowerThresholdFatal"]))
        {
            m_current_status["RxPower"]["Status"]["Health"] = "Critical";
            m_current_status["RxPower"]["Status"]["State"] = "Enabled";
        }
        else
        {
            m_current_status["RxPower"]["Status"]["Health"] = "OK";
            m_current_status["RxPower"]["Status"]["State"] = "Enabled";
        }
        /*RxPower Current End      :*/
    }
    catch (const exception &e)
    {
        printf("refresh_rx_pwr error\r\n");
        return;
    }
}

void e_oom::default_rx_pwr()
{
    /*RxPower Current Begin      :*/
    m_current_status["RxPower"]["UpperThresholdFatal"] = 0;
    m_current_status["RxPower"]["LowerThresholdFatal"] = 0;
    m_current_status["RxPower"]["UpperThresholdCritical"] = 0;
    m_current_status["RxPower"]["LowerThresholdCritical"] = 0;
    m_current_status["RxPower"]["Reading"] = 0;
    m_current_status["RxPower"]["Status"]["Health"] = json::Value::Type::NIL;
    m_current_status["RxPower"]["Status"]["State"] = json::Value::Type::NIL;
    /*RxPower Current End      :*/
}

bool e_oom::refresh_status()
{
    if (get_support())
    {
        /*Threshold value / Vendor info / olny get once until un-plug or restart service*/
        refresh_vendor_info();
        refresh_temp();
        refresh_voltage();
        refresh_bias();
        refresh_tx_pwr();
        refresh_rx_pwr();
    }
    return true;
}

bool e_oom::status_default()
{
    default_vendor_info();
    default_temp();
    default_voltage();
    default_bias();
    default_tx_pwr();
    default_rx_pwr();
    return true;
}

bool e_oom::get_eeprom_raw()
{
    std::ifstream is;
    is.rdbuf()->pubsetbuf(0, 0); // do not buffer //
    try
    {
        if (is)
        {
            is.seekg(0, is.beg);
            char buffer[SIZE_EEPROM] = {0};
            std::cout << "Port[" << m_eeprom_path << "] reading " << SIZE_EEPROM << " characters.." << std::endl;
#if 1
            is.open(m_eeprom_path);
#else
            //Read raw data file for testing //
            is.open("/outputfile.bin");
#endif
            if (is)
            {
                is.read(buffer, SIZE_EEPROM);
                if (store_eeprom(buffer))
                {
#if 0 //for debug usage            
                    int i = 0; 
                        while(i < SIZE_EEPROM)
                    {
                        printf("%02x ", (unsigned char)buffer[i]);
                        i++;
                        if(i % 8 == 0)
                            printf("\r\n");
                    }
#endif
                    refresh_status();
                }
                else
                    status_default();

                is.close();
            }
            else
                std::cout << "Open" << m_eeprom_path << " error!!" << std::endl;
        }
        else
        {
            std::cout << "Port[" << m_eeprom_path << "] reading file error!!" << std::endl;
            status_default();
            return false;
        }
        return true;
    }
    catch (const std::exception &e)
    {
        std::cout << "get_eeprom_raw() - exception : " << e.what() << std::endl;
        return false;
    }
}

bool e_oom::get_eeprom_raw(int rindex)
{
    try
    {
        int rv;
        uint8_t data[256];

        if ((rv = onlp_sfpi_eeprom_read(rindex, data)) < 0)
        {
            printf("onlp_sfpi_eeprom_read error!!\r\n");
        }
        else
        {
            printf("onlp_sfpi_eeprom_read [%d] ok!!\r\n", rindex);

            int i = 0;
            while (i < 256)
            {
                printf("%02x ", (unsigned char)data[i]);
                i++;
                if (i % 8 == 0)
                    printf("\r\n");
            }

            if (store_eeprom((char *)data))
            {
                refresh_status();
            }
        }
        return true;
    }
    catch (const std::exception &e)
    {
        std::cout << "get_eeprom_raw() rindex - exception : " << e.what() << std::endl;
        return false;
    }
}

Json::Value e_oom::get_attri_by_name(std::string att_name, Json::Value in)
{
    try
    {
        Json::Value PN_Json;
        int size = in.size();

        for (int i = 0; i < size; i++)
        {
            if (in[i].isMember(att_name))
            {
                //printf("get_attri_by_name return [%d]\r\n", i);
                return in[i];
            }
        }
        return PN_Json;
    }
    catch (const std::exception &e)
    {
        Json::Value PN_Json;

        std::cout << "get_attri_by_name() - exception : " << e.what() << std::endl;
        return PN_Json;
    }
}

// ------------------------------------------------------------------
//  New Transceiver Type need Added here
//  1. Decide by identify ID,
//     03h : SFP+  (10GPON) ,  8472i
//     06h : XFP   (XGSPON) ,  8077i
//     0dh : QSFP+ (40G)    ,  8436i
//     11h : QSFP28(100G)   ,  8438i
//  2. Identify which Std. should be used.
//  3. Store raw data.
// ------------------------------------------------------------------

bool e_oom::store_eeprom(char *in_eeprom)
{
    try
    {
        int id = in_eeprom[0];

        printf("store_eeprom id[0x%02X]\r\n", id);

        if (!get_support())
        {
            if (id == 0x6)
            {
                int size = m_8077i.size();
                Json::Value tmp_std;

                for (int i = 1; i <= size; i++)
                {
                    tmp_std = m_8077i[std::make_pair(id, i)];
                    std::string C_PN = tmp_std["C_PN"].asString();

                    printf("8077 C_PN[%s]\r\n\r\n", C_PN.c_str());

                    Json::Value Att_Json = tmp_std["Attributes"];
                    Json::Value PN_Json = get_attri_by_name("Vendor_PN", Att_Json);

                    int PN_Base = PN_Json["Vendor_PN"]["Byte_Address"].asInt();
                    //printf("PN_Base offset[%d]\r\n", PN_Base);
                    unsigned int PN_Size = PN_Json["Vendor_PN"]["Size"].asInt();
                    //printf("PN_Base Size[%d]\r\n", PN_Size);

                    if (C_PN.size() < PN_Size)
                    {
                        char tmp_PN[64] = {0};
                        memcpy(tmp_PN, in_eeprom + PN_Base, C_PN.size());
                        printf("tmp_PN[%s]\r\n", tmp_PN);
                        std::string tstring = tmp_PN;

                        if (tstring == C_PN)
                        {
                            m_std = tmp_std;
                            printf("8077i Use C_PN[%s] !!!!\r\n", C_PN.c_str());
                            set_support(true);
                            memcpy(m_eeprom, in_eeprom, SIZE_EEPROM);
                            return true;
                        }
                    }
                }

                // Use 8077i as default //
                std::string STD_PN = "8077i";
                m_std = tmp_std;
                printf("8077i Cannot get customer's define. Use Std[%s] one.\r\n", STD_PN.c_str());
                set_support(true);

                memcpy(m_eeprom, in_eeprom, SIZE_EEPROM);

                return true;
            }
            else if (id == 0x3)
            {
                int size = m_8472.size();
                Json::Value tmp_std;

                for (int i = 1; i <= size; i++)
                {
                    tmp_std = m_8472[std::make_pair(id, i)];
                    std::string C_PN = tmp_std["C_PN"].asString();
                    std::string STD_PN = "8472";

                    printf("8472 C_PN[%s]\r\n", C_PN.c_str());

                    Json::Value Att_Json = tmp_std["Attributes"];

                    Json::Value PN_Json = get_attri_by_name("Vendor_PN", Att_Json);

                    int PN_Base = PN_Json["Vendor_PN"]["Byte_Address"].asInt();
                    printf("PN_Base offset[%d]\r\n", PN_Base);

                    unsigned int PN_Size = PN_Json["Vendor_PN"]["Size"].asInt();
                    printf("PN_Base Size[%d]\r\n", PN_Size);

                    if (C_PN.size() < PN_Size)
                    {
                        char tmp_PN[64] = {0};
                        memcpy(tmp_PN, in_eeprom + PN_Base, C_PN.size());
                        printf("8472 tmp_PN[%s]\r\n", tmp_PN);
                        std::string tstring = tmp_PN;

                        if (tstring == C_PN)
                        {
                            m_std = tmp_std;
                            printf("8472 Use C_PN[%s] !!!!\r\n", C_PN.c_str());
                            set_support(true);
                            memcpy(m_eeprom, in_eeprom, SIZE_EEPROM);
                            return true;
                        }
                    }
                }

                // Use 8472 as default //
                std::string STD_PN = "8472";
                m_std = tmp_std;
                printf("Cannot get customer's define. Use Std[%s] one.\r\n", STD_PN.c_str());
                set_support(true);
                memcpy(m_eeprom, in_eeprom, SIZE_EEPROM);

                return true;
            }
            else if (id == 0x11)
            {
                int size = m_8438i.size();
                Json::Value tmp_std;

                for (int i = 1; i <= size; i++)
                {
                    tmp_std = m_8438i[std::make_pair(0x11, i)];
                    std::string C_PN = tmp_std["C_PN"].asString();
                    std::string STD_PN = "8438";

                    printf("8438 C_PN[%s]\r\n", C_PN.c_str());

                    Json::Value Att_Json = tmp_std["Attributes"];

                    Json::Value PN_Json = get_attri_by_name("Vendor_PN", Att_Json);

                    int PN_Base = PN_Json["Vendor_PN"]["Byte_Address"].asInt();
                    printf("PN_Base offset[%d]\r\n", PN_Base);

                    unsigned int PN_Size = PN_Json["Vendor_PN"]["Size"].asInt();
                    printf("PN_Base Size[%d]\r\n", PN_Size);

                    if (C_PN.size() < PN_Size)
                    {
                        char tmp_PN[64] = {0};
                        memcpy(tmp_PN, in_eeprom + PN_Base, C_PN.size());
                        printf("8438 tmp_PN[%s]\r\n", tmp_PN);
                        std::string tstring = tmp_PN;

                        if (tstring == C_PN)
                        {
                            m_std = tmp_std;
                            printf("8438 Use C_PN[%s] !!!!\r\n", C_PN.c_str());
                            set_support(true);
                            memcpy(m_eeprom, in_eeprom, SIZE_EEPROM);
                            return true;
                        }
                    }
                }

                // Use 8438 as default //
                std::string STD_PN = "8438";
                m_std = tmp_std;
                printf("Cannot get customer's define. Use Std[%s] one.\r\n", STD_PN.c_str());
                set_support(true);
                memcpy(m_eeprom, in_eeprom, SIZE_EEPROM);

                return true;
            }
            else if (id == 0x0d)
            {
                int size = m_8436i.size();
                Json::Value tmp_std;

                for (int i = 1; i <= size; i++)
                {
                    tmp_std = m_8436i[std::make_pair(0x0d, i)];
                    std::string C_PN = tmp_std["C_PN"].asString();
                    std::string STD_PN = "8436";

                    printf("8436 C_PN[%s]\r\n", C_PN.c_str());

                    Json::Value Att_Json = tmp_std["Attributes"];

                    Json::Value PN_Json = get_attri_by_name("Vendor_PN", Att_Json);

                    int PN_Base = PN_Json["Vendor_PN"]["Byte_Address"].asInt();
                    printf("PN_Base offset[%d]\r\n", PN_Base);

                    unsigned int PN_Size = PN_Json["Vendor_PN"]["Size"].asInt();
                    printf("PN_Base Size[%d]\r\n", PN_Size);

                    if (C_PN.size() < PN_Size)
                    {
                        char tmp_PN[64] = {0};
                        memcpy(tmp_PN, in_eeprom + PN_Base, C_PN.size());
                        printf("8436 tmp_PN[%s]\r\n", tmp_PN);
                        std::string tstring = tmp_PN;

                        if (tstring == C_PN)
                        {
                            m_std = tmp_std;
                            printf("8436 Use C_PN[%s] !!!!\r\n", C_PN.c_str());
                            set_support(true);
                            memcpy(m_eeprom, in_eeprom, SIZE_EEPROM);
                            return true;
                        }
                    }
                }

                // Use 8436 as default //
                std::string STD_PN = "8436";
                m_std = tmp_std;
                printf("Cannot get customer's define. Use Std[%s] one.\r\n", STD_PN.c_str());
                set_support(true);
                memcpy(m_eeprom, in_eeprom, SIZE_EEPROM);

                return true;
            }
            else
            {
                printf("Not support Std.\r\n");
                return false;
            }
        }
        else
            memcpy(m_eeprom, in_eeprom, SIZE_EEPROM);

        return true;
    }
    catch (const std::exception &e)
    {
        std::cout << "store_eeprom() - exception : " << e.what() << std::endl;
        return false;
    }
}

void e_oom::set_proto()
{
    m_current_status["SFP Vendor Name"] = json::Value::Type::NIL;
    m_current_status["Part Number"] = json::Value::Type::NIL;
    m_current_status["Serial Number"] = json::Value::Type::NIL;
    m_current_status["Manufacture Date"] = json::Value::Type::NIL;

    json::Value Temperatures(json::Value::Type::OBJECT);

    Temperatures["Reading"] = json::Value::Type::NIL;
    Temperatures["UpperThresholdFatal"] = json::Value::Type::NIL;
    Temperatures["UpperThresholdCritical"] = json::Value::Type::NIL;
    Temperatures["UpperThresholdNonCritical"] = json::Value::Type::NIL;
    Temperatures["LowerThresholdNonCritical"] = json::Value::Type::NIL;
    Temperatures["LowerThresholdCritical"] = json::Value::Type::NIL;
    Temperatures["LowerThresholdFatal"] = json::Value::Type::NIL;

    Temperatures["Status"]["HealthRollup"] = json::Value::Type::NIL;
    Temperatures["Status"]["Health"] = json::Value::Type::NIL;
    Temperatures["Status"]["State"] = json::Value::Type::NIL;

    m_current_status["Temperature"] = std::move(Temperatures);

    json::Value Bias(json::Value::Type::OBJECT);

    Bias["Reading"] = json::Value::Type::NIL;
    Bias["UpperThresholdFatal"] = json::Value::Type::NIL;
    Bias["UpperThresholdCritical"] = json::Value::Type::NIL;
    Bias["UpperThresholdNonCritical"] = json::Value::Type::NIL;
    Bias["LowerThresholdNonCritical"] = json::Value::Type::NIL;
    Bias["LowerThresholdCritical"] = json::Value::Type::NIL;
    Bias["LowerThresholdFatal"] = json::Value::Type::NIL;

    Bias["Status"]["HealthRollup"] = json::Value::Type::NIL;
    Bias["Status"]["Health"] = json::Value::Type::NIL;
    Bias["Status"]["State"] = json::Value::Type::NIL;

    m_current_status["BiasCurrent"] = std::move(Bias);

    json::Value Voltage(json::Value::Type::OBJECT);

    Voltage["Reading"] = json::Value::Type::NIL;
    Voltage["UpperThresholdFatal"] = json::Value::Type::NIL;
    Voltage["UpperThresholdCritical"] = json::Value::Type::NIL;
    Voltage["UpperThresholdNonCritical"] = json::Value::Type::NIL;
    Voltage["LowerThresholdNonCritical"] = json::Value::Type::NIL;
    Voltage["LowerThresholdCritical"] = json::Value::Type::NIL;
    Voltage["LowerThresholdFatal"] = json::Value::Type::NIL;

    Voltage["Status"]["HealthRollup"] = json::Value::Type::NIL;
    Voltage["Status"]["Health"] = json::Value::Type::NIL;
    Voltage["Status"]["State"] = json::Value::Type::NIL;

    m_current_status["Voltage"] = std::move(Voltage);

    json::Value TxPwr(json::Value::Type::OBJECT);

    TxPwr["Reading"] = json::Value::Type::NIL;
    TxPwr["UpperThresholdFatal"] = json::Value::Type::NIL;
    TxPwr["UpperThresholdCritical"] = json::Value::Type::NIL;
    TxPwr["UpperThresholdNonCritical"] = json::Value::Type::NIL;
    TxPwr["LowerThresholdNonCritical"] = json::Value::Type::NIL;
    TxPwr["LowerThresholdCritical"] = json::Value::Type::NIL;
    TxPwr["LowerThresholdFatal"] = json::Value::Type::NIL;

    TxPwr["Status"]["HealthRollup"] = json::Value::Type::NIL;
    TxPwr["Status"]["Health"] = json::Value::Type::NIL;
    TxPwr["Status"]["State"] = json::Value::Type::NIL;

    m_current_status["TxPower"] = std::move(TxPwr);

    json::Value RxPwr(json::Value::Type::OBJECT);

    RxPwr["Reading"] = json::Value::Type::NIL;
    RxPwr["UpperThresholdFatal"] = json::Value::Type::NIL;
    RxPwr["UpperThresholdCritical"] = json::Value::Type::NIL;
    RxPwr["UpperThresholdNonCritical"] = json::Value::Type::NIL;
    RxPwr["LowerThresholdNonCritical"] = json::Value::Type::NIL;
    RxPwr["LowerThresholdCritical"] = json::Value::Type::NIL;
    RxPwr["LowerThresholdFatal"] = json::Value::Type::NIL;

    RxPwr["Status"]["HealthRollup"] = json::Value::Type::NIL;
    RxPwr["Status"]["Health"] = json::Value::Type::NIL;
    RxPwr["Status"]["State"] = json::Value::Type::NIL;

    m_current_status["RxPower"] = std::move(RxPwr);
}

// ------------------------------------------------------------------
//  1. Decide by identify ID,
//     03h : SFP+  (10GPON) ,  8472i
//     06h : XFP   (XGSPON) ,  8077i
//     0dh : QSFP+ (40G)    ,  8436i
//     11h : QSFP28(100G)   ,  8438i
//  2. Take customer PN to compare first.
//  3. If not find PN in customer PN, use std instead
// ------------------------------------------------------------------

bool e_oom::get_conf()
{
    try
    {
        //New Transceiver Type need Added here begin//
        int count_8077i = 0;
        int count_8472 = 0;
        int count_8438i = 0;
        int count_8436i = 0;
        //New Transceiver Type need Added here end//

        std::string ME_S_DIR(STD_SEC_PATH);
        struct dirent *entry;

        if (m_support == true)
            return true;

        DIR *dir = opendir(ME_S_DIR.c_str());

        if (dir == NULL)
        {
            printf("no such path exist!!\r\n");
            return false;
        }

        while ((entry = readdir(dir)) != NULL)
        {
            std::string dot(".");
            std::string ddot("..");
            std::string maps("map");

            std::string tmp_me_name = entry->d_name;

            if ((dot == tmp_me_name) || (ddot == tmp_me_name) || (maps == tmp_me_name))
                continue;

            //printf("std name[%s] \r\n", tmp_me_name.c_str());
            std::string m_config_file_path = ME_S_DIR + tmp_me_name;
            //printf("new pathname[%s]\r\n",  m_config_file_path.c_str());

            std::ifstream m_source_files = {};

            m_source_files.open(m_config_file_path);

            if (m_source_files.good())
            {
                Json::Value std_s;
                Json::Reader reader;
                bool isJsonOK = (reader.parse(m_source_files, std_s));
                //New Transceiver Type need Added here//
                if (isJsonOK)
                {
                    //New Transceiver Type need Added here begin//
                    int id = std::stoi(std_s["Identifer"].asString(), 0, 16);
                    if (id == 0x06)
                    {
                        count_8077i++;
                        //printf("0x06 Identifer[%s]\r\n",std_s["Identifer"].asString().c_str());
                        //printf("Set id[%d] count_std[%d] TRANS_TYPE_8077I\r\n", id, count_8077i);
                        m_8077i[std::make_pair(id, count_8077i)] = std_s;
                    }
                    else if (id == 0x03)
                    {
                        count_8472++;
                        //printf("0x03 Identifer[%s]\r\n",std_s["Identifer"].asString().c_str());
                        //printf("Set id[%d] count_std[%d] TRANS_TYPE_8472\r\n", id, count_8472);
                        m_8472[std::make_pair(id, count_8472)] = std_s;
                    }
                    else if (id == 0x11)
                    {
                        count_8438i++;
                        //printf("0x0B Identifer[%s]\r\n",std_s["Identifer"].asString().c_str());
                        //printf("Set id[%d] count_std[%d] TRANS_TYPE_8438\r\n", id, count_8438i);
                        m_8438i[std::make_pair(id, count_8438i)] = std_s;
                    }
                    else if (id == 0x0d)
                    {
                        count_8436i++;
                        printf("0x0d Identifer[%s]\r\n", std_s["Identifer"].asString().c_str());
                        printf("Set id[%d] count_std[%d] TRANS_TYPE_8436\r\n", id, count_8436i);
                        m_8436i[std::make_pair(id, count_8436i)] = std_s;
                    }
                    else
                        printf("Can't identifiy!!\r\n");
                    //New Transceiver Type need Added here end//
                }
                else
                {
                    printf("Get conf_s ng\r\n");
                    closedir(dir);
                    m_source_files.close();
                    return false;
                }
            }
            else
            {
                printf("Open file NG\r\n");
                m_source_files.close();
                closedir(dir);
                return false;
            }
        }
        closedir(dir);
        return true;
    }
    catch (const std::exception &e)
    {
        std::cout << "get_conf() - exception : " << e.what() << std::endl;
        return false;
    }
}

static Acc_Switch *g_Switch = NULL;

//For print debug //
auto &gADbg = ADbg::get_instance();

void Acc_Switch::get_board_info()
{
    std::lock_guard<std::mutex> lock{m_data_mutex};
    gADbg.acc_printf("/////////start get_board_info////////////\r\n");

    try
    {
        std::ifstream m_ifile(m_platinfo_path);
        Json::Value content;

        if (m_ifile.good())
        {
            Json::Reader reader;
            bool isJsonOK = (reader.parse(m_ifile, content));

            if (isJsonOK)
            {
                const Json::Value defValue; //used for default reference
                const Json::Value s = content.get("managers", defValue);

                if (get_fan_num() > 0)
                {
                    int i = 0;

                    for (i = 1; i <= get_fan_num(); i++)
                    {
                        Fan_Info *p = NULL;
                        std::string findex("fan");

                        if (s[0]["onlp"]["fans"][findex + std::to_string(i)].asString() == "System")
                        {
                            p = new SYS_Fan();
                            p->m_ID = i;
                            p->m_Type = Fan_Info::SYSTEM_Fan;
                        }
                        else if (s[0]["onlp"]["fans"][findex + std::to_string(i)].asString() == "Psu")
                        {
                            p = new SYS_Fan();
                            p->m_ID = i;
                            p->m_Type = Fan_Info::PSU_Fan;
                        }
                        else
                        {
                            p = new SYS_Fan();
                            p->m_ID = i;
                            p->m_Type = Fan_Info::SYSTEM_Fan;
                        }
                        m_vec_Fan_Info.push_back(p);
                    }
                }

                m_port_max_num = s[0]["onlp"]["port_max_num"].asInt();

                if (m_port_max_num > 0)
                {
                    /*Get mapping json file*/
                    Json::Value mapping_s;

                    std::ifstream ifs(m_onl_platinfo_path);
                    getline(ifs, m_onl_platinfo_name, (char)ifs.eof());
                    m_onl_platinfo_name.erase(std::remove(m_onl_platinfo_name.begin(), m_onl_platinfo_name.end(), '\n'), m_onl_platinfo_name.end());
                    int str_size = m_onl_platinfo_name.size() - 3; //Remove "-r0" or "-r1" ...etc
                    m_onl_platinfo_name.resize(str_size);
                    printf("m_onl_platinfo_name[%s]\r\n", m_onl_platinfo_name.c_str());

                    std::string mapping_file_path = PORT_MAP_PATH + m_onl_platinfo_name;
                    printf("mapping_file_path[%s]\r\n", mapping_file_path.c_str());

                    std::ifstream map_files(mapping_file_path);

                    bool isJson = (m_eeprom_j_reader.parse(map_files, mapping_s));

                    if (isJson)
                    {
                        printf("Get eeprom mapping file ok!!\r\n");
                    }
                    else
                        printf("Get eeprom mapping file error!!\r\n");

                    int i = 0;
                    for (i = 1; i <= m_port_max_num; i++)
                    {
                        Port_Info *p = NULL;
                        p = new Port_Info();
                        p->m_ID = i;

                        std::string findex("port");
                        if (s[0]["onlp"]["ports"][findex + std::to_string(i)].asString() == "Ether")
                            p->m_Type = Port_Info::Ether_Port;
                        else if (s[0]["onlp"]["ports"][findex + std::to_string(i)].asString() == "SFP")
                        {
                            p->m_Type = Port_Info::SFP_Port;
                            /*Set SFP eeprom mapping path*/
                            printf("set_eeprom_path port [%d] [%s]!!\r\n \r\n", i, mapping_s[std::to_string(i)].asString().c_str());
                            p->set_eeprom_path(mapping_s[std::to_string(i)].asString());
                        }
                        else if (s[0]["onlp"]["ports"][findex + std::to_string(i)].asString() == "QSFP")
                        {
                            p->m_Type = Port_Info::QSFP_Port;
                            /*Set SFP eeprom mapping path*/
                            printf("set_eeprom_path port [%d] [%s]!!\r\n \r\n", i, mapping_s[std::to_string(i)].asString().c_str());
                            p->set_eeprom_path(mapping_s[std::to_string(i)].asString());
                        }
                        else if (s[0]["onlp"]["ports"][findex + std::to_string(i)].asString() == "PON")
                        {
                            p->m_Type = Port_Info::PON_Port;
                            /*Set PON eeprom mapping path*/
                            printf("set_eeprom_path port [%d] [%s]!!\r\n \r\n", i, mapping_s[std::to_string(i)].asString().c_str());
                            p->set_eeprom_path(mapping_s[std::to_string(i)].asString());
                        }
                        else
                            p->m_Type = Port_Info::Ether_Port;

                        m_vec_Port_Info.push_back(p);
                    }
                }

                if (get_thermal_num() > 0)
                {
                    int i = 0;
                    for (i = 1; i <= get_thermal_num(); i++)
                    {
                        Thermal_Info *p = NULL;

                        std::string findex("thermal");

                        if (s[0]["onlp"]["thermals"][findex + std::to_string(i)].asString() == "CPU")
                        {
                            printf("C  CPU_Thermal  \r\n");

                            p = new CPU_Thermal();
                            p->m_ID = i;
                            p->m_Type = Thermal_Info::CPU_Sensor;
                            m_vec_Thermal_Info.push_back(p);
                        }
                        else if (s[0]["onlp"]["thermals"][findex + std::to_string(i)].asString() == "System")
                        {
                            printf("C  SYS_Thermal  \r\n");

                            p = new SYS_Thermal();
                            p->m_ID = i;
                            p->m_Type = Thermal_Info::SYSTEM_Sensor;
                            m_vec_Thermal_Info.push_back(p);
                        }
                        else if (s[0]["onlp"]["thermals"][findex + std::to_string(i)].asString() == "Psu")
                        {
                            printf("C  PSU_Thermal  \r\n");
                            p = new PSU_Thermal();
                            p->m_ID = i;
                            p->m_Type = Thermal_Info::PSU_Sensor;
                            m_vec_Thermal_Info.push_back(p);
                        }
                        else
                            printf("THERMLA create ERROR\r\n!!");
                    }
                }

                if (get_psu_num() > 0)
                {
                    int i = 0;
                    for (i = 1; i <= get_psu_num(); i++)
                    {
                        Psu_Info *p = NULL;
                        p = new Psu_Info();
                        p->m_ID = i;

                        std::string findex("psu");

                        if (s[0]["onlp"]["psus"][findex + std::to_string(i)].asString() == "System")
                            p->m_Type = Psu_Info::SYSTEM;
                        else
                            p->m_Type = Psu_Info::SYSTEM;

                        m_vec_Psu_Info.push_back(p);
                    }
                }

                m_cpu_stepping = s[0]["onlp"]["cpu_stepping"].asInt();
                m_cpu_max_speed = s[0]["onlp"]["cpu_max_speed"].asInt();
                m_cpu_total_core = s[0]["onlp"]["cpu_total_core"].asInt();
                m_cpu_total_thread = s[0]["onlp"]["cpu_total_thread"].asInt();
                m_memory_total_count = s[0]["onlp"]["memory_total_count"].asInt();
                m_drv_total_count = s[0]["onlp"]["drv_total_count"].asInt();
                m_cpu_manu = s[0]["onlp"]["cpu_manu"].asString();
                m_cpu_vid = s[0]["onlp"]["cpu_vid"].asString();
                m_cpu_model_name = s[0]["onlp"]["cpu_model_name"].asString();

                gADbg.acc_printf("/////////////////////\r\n");
                gADbg.acc_printf("m_fan_max_num[%d]\r\n", get_fan_num());
                gADbg.acc_printf("m_port_max_num[%d]\r\n", m_port_max_num);
                gADbg.acc_printf("m_thermal_sen_max_num[%d]\r\n", get_thermal_num());
                gADbg.acc_printf("m_psu_max_num[%d]\r\n", get_psu_num());
                gADbg.acc_printf("m_cpu_stepping[%d]\r\n", m_cpu_stepping);
                gADbg.acc_printf("m_cpu_max_speed[%d]\r\n", m_cpu_max_speed);
                gADbg.acc_printf("m_cpu_total_core[%d]\r\n", m_cpu_total_core);
                gADbg.acc_printf("m_cpu_total_thread[%d]\r\n", m_cpu_total_thread);
                gADbg.acc_printf("m_memory_total_count[%d]\r\n", m_memory_total_count);
                gADbg.acc_printf("m_drv_total_count[%d]\r\n", m_drv_total_count);
                gADbg.acc_printf("m_cpu_manu[%s]\r\n", m_cpu_manu.c_str());
                gADbg.acc_printf("m_cpu_vid[%s]\r\n", m_cpu_vid.c_str());
                gADbg.acc_printf("m_cpu_model_name[%s]\r\n", m_cpu_model_name.c_str());

                /**/
                m_ifile.close();
            }
            else
                gADbg.acc_printf("get_board_info error\r\n");
        }
        else
            gADbg.acc_printf("[%s] file not exist\r\n", m_platinfo_path.c_str());

        gADbg.acc_printf("/////////end get_board_info////////////\r\n");
    }
    catch (const std::exception &ex)
    {
        std::cout << "get_board_info() - exception : " << ex.what() << std::endl;
        return;
    }
}

void Acc_Switch::get_port_present_info()
{
    try
    {
        std::lock_guard<std::mutex> lock{m_data_mutex};

        int ii = 0;

        for (ii = 1; ii <= m_port_max_num; ii++)
        {
            for (vector<Port_Info *>::iterator pObj = m_vec_Port_Info.begin(); pObj != m_vec_Port_Info.end(); ++pObj)
            {
                if ((*pObj)->m_ID == ii)
                {
                    if ((*pObj)->m_Type == Port_Info::Ether_Port)
                    {
                        set_port_present(ii, true);
                        (*pObj)->set_info(ii, Port_Info::Ether_Port, 1, true); // Type 1: XFP // Type 2 : ETHER
                        gADbg.acc_printf("s Ether Port ID: %d\r\n", (*pObj)->m_ID);
                        gADbg.acc_printf("s Port present status [%d]\r\n", 1);
                    }
                    else
                    {
                        int rindex = ii - 1; //Need start from 0//
                        int b = onlp_sfpi_is_present(rindex);

                        if (b)
                        {
                            gADbg.acc_printf("SFP port [%d] present\r\n", ii);
                            set_port_present(ii, true);
                            (*pObj)->set_info(ii, (*pObj)->m_Type, 1, true);
                        }
                        else
                        {
                            gADbg.acc_printf("SFP port [%d] not present\r\n", ii);
                            set_port_present(ii, false);
                            (*pObj)->set_info(ii, (*pObj)->m_Type, 0, false);
                            (*pObj)->clean_trans_data();
                        }
                    }
                }
            }
        }
        return;
    }
    catch (const std::exception &e)
    {
        std::cout << "get_port_present_info() - exception : " << e.what() << std::endl;
        return;
    }
}

void Acc_Switch::get_port_oom_info()
{
    try
    {
        std::lock_guard<std::mutex> lock{m_data_mutex};

        int ii = 0;

        for (ii = 1; ii <= m_port_max_num; ii++)
        {
            for (vector<Port_Info *>::iterator pObj = m_vec_Port_Info.begin(); pObj != m_vec_Port_Info.end(); ++pObj)
            {
                if ((*pObj)->m_ID == ii)
                {
                    if ((*pObj)->m_Type == Port_Info::Ether_Port)
                    {
                        set_port_present(ii, true);
                        (*pObj)->set_info(ii, Port_Info::Ether_Port, 1, true);
                        gADbg.acc_printf("s Ether Port ID: %d\r\n", (*pObj)->m_ID);
                        gADbg.acc_printf("s Port present status [%d]\r\n", 1);
                    }
                    else
                    {
                        int rindex = ii - 1; //Need start from 0//
                        int b = onlp_sfpi_is_present(rindex);

                        if (b)
                        {
                            gADbg.acc_printf("SFP port [%d] present\r\n", ii);
#if 1
                            if (!(*pObj)->get_eeprom_raw())
                            {
                                gADbg.acc_printf("catch eeprom 8472 data error");
                            }
                            else
                            {
                                gADbg.acc_printf("catch eeprom 8472 data ok");
                            }
#else
                            //Use ONLP API to get EEPROM data, but only 256 bytes , not enough ..//
                            if (!(*pObj)->get_eeprom_raw(rindex))
                            {
                                gADbg.acc_printf("catch eeprom 8077I data error");
                            }
                            else
                            {
                                gADbg.acc_printf("catch eeprom 8077I data ok");
                            }
#endif
                        }
                        else
                        {
                            gADbg.acc_printf("SFP port [%d] not present\r\n", ii);
                            (*pObj)->clean_trans_data();
                        }
                    }
                }
            }
        }
        return;
    }
    catch (const std::exception &e)
    {
        std::cout << "get_port_oom_info() - exception : " << e.what() << std::endl;
        return;
    }
}

void Acc_Switch::get_thermal_info()
{
    try
    {
        int rv;
        onlp_thermal_info_t fv;
        int ii = 0;

        for (ii = 1; ii <= get_thermal_num(); ii++)
        {
            unsigned int id = ONLP_THERMAL_ID_CREATE(ii);
            rv = onlp_thermal_info_get(id, &fv);

            gADbg.acc_printf("/////////////////////////\r\n");

            for (vector<Thermal_Info *>::iterator pObj = m_vec_Thermal_Info.begin(); pObj != m_vec_Thermal_Info.end(); ++pObj)
            {
                if ((*pObj)->m_ID == ii)
                {
                    if (rv < 0 && (*pObj)->m_ID == ii)
                    {
                        set_thermal_present(ii, false);
                        (*pObj)->set_info(ii, 0, 0, 0, 0, false);
                        gADbg.acc_printf("get_thermal_info [%d] error\r\n", ii);
                    }
                    else
                    {
                        if (fv.status & 1)
                        {
                            set_thermal_present(ii, true);
                            (*pObj)->set_info(ii, fv.mcelsius, fv.thresholds.warning, fv.thresholds.error, fv.thresholds.shutdown, true);
                            gADbg.acc_printf("s thermal ID: %d\r\n", (*pObj)->m_ID);
                            gADbg.acc_printf("s thermal Temperature: %d\r\n", (*pObj)->m_Current_Temperature);
                            gADbg.acc_printf("s thermal Warning: %d\r\n", (*pObj)->m_Warning);
                            gADbg.acc_printf("s thermal Error: %d\r\n", (*pObj)->m_Error);
                            gADbg.acc_printf("s thermal Shutdown: %d\r\n", (*pObj)->m_Shutdown);
                        }
                        else
                        {
                            gADbg.acc_printf("Thermal [%d] Not present.\r\n", ii);
                            set_thermal_present(ii, false);
                            (*pObj)->set_info(ii, fv.mcelsius, fv.thresholds.warning, fv.thresholds.error, fv.thresholds.shutdown, false);
                        }
                    }
                }
            }
        }
        gADbg.acc_printf("THERMAL PRESNET [0x%04x]\r\n\r\n", get_thermal_present());
        gADbg.acc_printf("/////////////////////////\r\n");
        return;
    }
    catch (const std::exception &e)
    {
        std::cout << "get_thermal_info() - exception : " << e.what() << std::endl;
        return;
    }
}

int Acc_Switch::get_port_tx_status(int port)
{
    try
    {
        std::lock_guard<std::mutex> lock{m_data_mutex};
        int ii = 0;
        for (ii = 1; ii <= m_port_max_num; ii++)
        {
            for (vector<Port_Info *>::iterator pObj = m_vec_Port_Info.begin(); pObj != m_vec_Port_Info.end(); ++pObj)
            {
                if ((*pObj)->m_ID == port)
                {
                    std::string sysfs_path = (*pObj)->get_sysfile_path();
                    return (*pObj)->get_tx_status(sysfs_path + m_sys_tx_name);
                }
            }
        }
        return -1;
    }
    catch (const std::exception &e)
    {
        std::cout << "get_port_tx_status() - exception : " << e.what() << std::endl;
        return -1;
    }
}

void Acc_Switch::set_port_tx_status(int port, bool tx_status)
{
    printf("Acc_Switch::set_port_tx_status port[%d] tx_status[%d]\r\n", port, tx_status);
    try
    {
        std::lock_guard<std::mutex> lock{m_data_mutex};
        int ii = 0;
        for (ii = 1; ii <= m_port_max_num; ii++)
        {
            for (vector<Port_Info *>::iterator pObj = m_vec_Port_Info.begin(); pObj != m_vec_Port_Info.end(); ++pObj)
            {
                if ((*pObj)->m_ID == port)
                {
                    std::string sysfs_path = (*pObj)->get_sysfile_path();
                    (*pObj)->set_tx(tx_status, sysfs_path + m_sys_tx_name);
                    return;
                }
            }
        }
        return;
    }
    catch (const std::exception &e)
    {
        std::cout << "set_port_tx_status() - exception : " << e.what() << std::endl;
        return;
    }
}

void Psu_Info::set_info(int ID, std::string Model, std::string SN, int Vin, int Vout, int Iin, int Iout, int Pin, int Pout, onlp_psu_type_t type, bool present)
{
    try
    {
        m_ID = ID;
        if (!Model.empty() && Model[Model.size() - 1] == '\n')
            Model.erase(Model.size() - 1);
        m_Model = Model;
        m_SN = SN;
        m_Vin = Vin;
        m_Vout = Vout;
        m_Iin = Iin;
        m_Iout = Iout;
        m_Pin = Pin;
        m_Pout = Pout;
        m_Present = present;
        m_Psu_Type = type;

        if (m_Type == SYSTEM)
        {
            if (present && (Pout == 0))
            {
                //PSU don't plugin power cord
                m_Status_Health = "OK";
                m_Status_State = "UnavailableOffline";
                gADbg.acc_printf("-----Psu_Info-----UnavailableOffline---\r\n");

                std::string event("Event");
                std::string servrity("Warning");
                std::string sensor_type("Power Supply / Converter");
                std::string message("PSU UnavailableOffline");
            }
            else if (present && (Pout > 0))
            {
                //PSU working normal
                m_Status_Health = "OK";
                m_Status_State = "Enabled";
                gADbg.acc_printf("-----Psu_Info-----PSU working normal---\r\n");
            }
            else if (!present)
            {
                //PSU un-plug //
                m_Status_Health = "Warning";
                m_Status_State = "Absent";
                gADbg.acc_printf("-----Psu_Info-----absent---\r\n");

                std::string event("Event");
                std::string servrity("Warning");
                std::string sensor_type("Power Supply / Converter");
                std::string message("PSU absent");
            }
            else
            {
                m_Status_Health = "Warning";
                m_Status_State = "Absent";
                gADbg.acc_printf("-----Psu_Info-----absent-2--\r\n");

                std::string event("Event");
                std::string servrity("Warning");
                std::string sensor_type("Power Supply / Converter");
                std::string message("PSU absent");
            }
        }

        return;
    }
    catch (const std::exception &e)
    {
        std::cout << "Psu_Info set_info() - exception : " << e.what() << std::endl;
        return;
    }
}

void Fan_Info::set_info(int ID, std::string Model, std::string SN, int RPM, int Per, bool present)
{
    try
    {
        m_ID = ID;
        m_Model = Model;
        m_SN = SN;
        m_RPM = RPM;
        m_Per = Per;
        m_Present = present;

        if (m_Type == SYSTEM_Fan)
        {
            if (present && (RPM == 0))
            {
                //Fan plug in but not SPIN
                m_Status_Health = "Warning";
                m_Status_State = "Enabled";
                gADbg.acc_printf("-----Fan_Info-----Fan plug in but not SPIN---\r\n");

                std::string event("Event");
                std::string servrity("Warning");
                std::string sensor_type("Fan");
                std::string message("Fan plug in but not SPIN");

                std::string message_event = std::string("Fan : ") + std::to_string(ID) + std::string("not SPIN.");
                if (!m_fan_alert)
                { //Only send alert once //
                    m_Event_Resouce_Alert.push_back(message_event);
                    m_fan_alert = true;
                }
            }
            else if (present && (RPM > 0))
            {
                //Fan working normal
                m_Status_Health = "OK";
                m_Status_State = "Enabled";
                gADbg.acc_printf("-----Fan_Info-----Fan working normal---\r\n");
                m_fan_alert = false;
            }
            else if (!present)
            {
                //FAN un-plug //
                m_Status_Health = "Warning";
                m_Status_State = "Absent";
                gADbg.acc_printf("-----Fan_Info-----absent---\r\n");

                std::string event("Event");
                std::string servrity("Warning");
                std::string sensor_type("Fan");
                std::string message("System fan absent");
            }
            else
            {
                m_Status_Health = "Warning";
                m_Status_State = "Absent";
                gADbg.acc_printf("-----Fan_Info-----absent-2--\r\n");
            }
        }
        else if (m_Type == PSU_Fan)
        {
            if (present && (RPM == 0))
            {
                //Fan plug in but not SPIN
                m_Status_Health = "Warning";
                m_Status_State = "Enabled";
                gADbg.acc_printf("-----PSU_Info-----PSU plug in but not no power core plug in---\r\n");

                std::string event("Event");
                std::string servrity("Warning");
                std::string sensor_type("Fan");
                std::string message("PSU plug in but not no power core plug in");
            }
            else if (present && (RPM > 0))
            {
                //PSU working normal
                m_Status_Health = "OK";
                m_Status_State = "Enabled";
                gADbg.acc_printf("-----PSU_Info-----PSU working normal---\r\n");
            }
            else if (!present)
            {
                //PSU un-plug //
                m_Status_Health = "Warning";
                m_Status_State = "Absent";
                gADbg.acc_printf("-----PSU_Info-----PSU absent---\r\n");

                std::string event("Event");
                std::string servrity("Warning");
                std::string sensor_type("Fan");
                std::string message("PSU fan absent");
            }
            else
            {
                m_Status_Health = "Warning";
                m_Status_State = "Absent";
                gADbg.acc_printf("-----PSU_Info-----PSU absent-2--\r\n");

                std::string event("Event");
                std::string servrity("Warning");
                std::string sensor_type("Fan");
                std::string message("PSU fan absent");
            }
        }
        else
        {
            gADbg.acc_printf("-----PSU_Info-----Unkonw type--\r\n");
            m_Status_Health = "Warning";
            m_Status_State = "Absent";
        }

        return;
    }
    catch (const std::exception &e)
    {
        std::cout << "Fan_Info set_info() - exception : " << e.what() << std::endl;
        return;
    }
}

void Thermal_Info::set_thermal_threshold_value(int Warning, int Error, int Shutdown)
{
    m_Warning = Warning;
    m_Error = Error;
    m_Shutdown = Shutdown;
}

void CPU_Thermal::set_thermal_threshold_value(int Warning, int Error, int Shutdown)
{
    //Todo , get from real time value //
    if ((Warning != 0 && Error != 0 && Shutdown != 0) && (m_Warning == 0 && m_Error == 0 && m_Shutdown == 0))
    {
        m_Warning = 82000;
        m_Error = 92000;
        m_Shutdown = 104000;
    }
}

void SYS_Thermal::set_thermal_threshold_value(int Warning, int Error, int Shutdown)
{
    m_Warning = Warning;
    m_Error = Error;
    m_Shutdown = Shutdown;
}

void PSU_Thermal::set_thermal_threshold_value(int Warning, int Error, int Shutdown)
{
    m_Warning = Warning;
    m_Error = Error;
    m_Shutdown = Shutdown;
}

void Thermal_Info::set_info(int ID, int Current_Temperature, int Warning, int Error, int Shutdown, bool present)
{
    try
    {

        m_ID = ID;
        m_Current_Temperature = Current_Temperature;
        m_Present = present;
        set_thermal_threshold_value(Warning, Error, Shutdown);
        /*
   Area : 1 
   "Warning" "Enabled"
   
   Zero-th        ----- un-available offline
   
   Area : 2
   "OK" "Enabled"
   
   Warning-th   -----
   
   Area : 3
   "OK" "Warning"
   
   Error-th       -----
   
   Area : 4
   "OK" "Warning"
   
   
   Shutdown-th ----
   
   Area : 5
   
   */
        if (m_Type == CPU_Sensor && present)
        {
            if ((m_Current_Temperature < 0) || ((m_Current_Temperature >= m_Warning) && (m_Current_Temperature < m_Error)))
            {
                //     Area : 1 / 3
                m_Status_Health = "Warning";
                m_Status_State = "Enabled";

                std::string event("Event");
                std::string servrity("Warning");
                std::string sensor_type("Temperature");
                std::string message;
                message = std::string("CPU Thermal is ") + std::to_string(m_Current_Temperature / 1000) + std::string(" degrees.Over warning temperature.");
                gADbg.acc_printf("set_info-----CPU_Sensor-----Warning--\r\n");

                if (m_cpu_thermal_alert != 1)
                {
                    m_Event_Resouce_Alert.push_back(message);
                    m_cpu_thermal_alert = 1;
                }
            }
            else if (((m_Current_Temperature >= m_Error)) && (m_Current_Temperature < m_Shutdown))
            {
                //     Area : 4

                m_Status_Health = "Warning";
                m_Status_State = "Enabled";

                std::string event("Event");
                std::string servrity("Warning");
                std::string sensor_type("Temperature");
                std::string message;
                message = std::string("CPU Thermal is ") + std::to_string(m_Current_Temperature / 1000) + std::string(" degrees.Over error temperature.");
                gADbg.acc_printf("set_info-----CPU_Sensor-----Warning--\r\n");

                if (m_cpu_thermal_alert != 4)
                {
                    m_Event_Resouce_Alert.push_back(message);
                    m_cpu_thermal_alert = 4;
                }
            }
            else if ((m_Current_Temperature >= m_Shutdown))
            {
                //     Area : 5
                m_Status_Health = "Critical";
                m_Status_State = "Enabled";

                std::string event("Event");
                std::string servrity("Warning");
                std::string sensor_type("Temperature");
                std::string message;
                message = std::string("CPU Thermal is ") + std::to_string(m_Current_Temperature / 1000) + std::string(" degrees.Over fatal temperature.");
                gADbg.acc_printf("set_info-----CPU_Sensor-----Critical--\r\n");

                if (m_cpu_thermal_alert != 5)
                {
                    m_Event_Resouce_Alert.push_back(message);
                    m_cpu_thermal_alert = 5;
                }
            }
            else
            {
                //     Area : 2

                m_Status_Health = "OK";
                m_Status_State = "Enabled";
                m_cpu_thermal_alert = 0;
            }
        }
        else if (m_Type == SYSTEM_Sensor && present)
        {
            if ((m_Current_Temperature < 0) || ((m_Current_Temperature >= m_Warning) && (m_Current_Temperature < m_Error)))
            {
                //     Area : 1 / 3
                m_Status_Health = "Warning";
                m_Status_State = "Enabled";

                std::string event("Event");
                std::string servrity("Warning");
                std::string sensor_type("Temperature");
                std::string message;
                message = std::string("SYSTEM Thermal is ") + std::to_string(m_Current_Temperature / 1000) + std::string(" degrees.Over warning temperature.");
                gADbg.acc_printf("set_info-----SYSTEM_Sensor-----Warning--\r\n");

                std::string message_event = std::string("SYSTEM Thermal ") + std::to_string(ID) + std::string(" is ") + std::to_string(m_Current_Temperature / 1000) +
                                            std::string(" degrees. Over warning temperature.");

                if (m_sys_thermal_alert != 1)
                {
                    m_Event_Resouce_Alert.push_back(message_event);
                    m_sys_thermal_alert = 1;
                }
            }
            else if (((m_Current_Temperature >= m_Error)) && (m_Current_Temperature < m_Shutdown))
            {
                //     Area : 4

                m_Status_Health = "Warning";
                m_Status_State = "Enabled";

                std::string event("Event");
                std::string servrity("Warning");
                std::string sensor_type("Temperature");
                std::string message;
                message = std::string("SYSTEM Thermal is ") + std::to_string(m_Current_Temperature / 1000) + std::string(" degrees.Over error temperature.");
                gADbg.acc_printf("set_info-----SYSTEM_Sensor-----Warning--\r\n");

                std::string message_event = std::string("SYSTEM Thermal ") + std::to_string(ID) + std::string(" is ") + std::to_string(m_Current_Temperature / 1000) +
                                            std::string(" degrees. Over error temperature.");

                if (m_sys_thermal_alert != 4)
                {
                    m_Event_Resouce_Alert.push_back(message_event);
                    m_sys_thermal_alert = 4;
                }
            }
            else if ((m_Current_Temperature >= m_Shutdown))
            {
                //     Area : 5
                m_Status_Health = "Critical";
                m_Status_State = "Enabled";

                std::string event("Event");
                std::string servrity("Critical");
                std::string sensor_type("Temperature");
                std::string message;
                message = std::string("SYSTEM_Sensor Thermal is ") + std::to_string(m_Current_Temperature / 1000) + std::string(" degrees.Over fatal temperature.");
                gADbg.acc_printf("set_info-----SYSTEM_Sensor-----Critical--\r\n");

                std::string message_event = std::string("SYSTEM Thermal ") + std::to_string(ID) + std::string(" is ") + std::to_string(m_Current_Temperature / 1000) +
                                            std::string(" degrees. Over fatal temperature.");

                if (m_sys_thermal_alert != 5)
                {
                    m_Event_Resouce_Alert.push_back(message_event);
                    m_sys_thermal_alert = 5;
                }
            }
            else
            {
                //     Area : 2

                m_Status_Health = "OK";
                m_Status_State = "Enabled";
                m_sys_thermal_alert = 0;
            }
        }
        else if (m_Type == PSU_Sensor && present)
        {
            if (m_Current_Temperature == 0)
            {
                m_Status_Health = "OK";
                m_Status_State = "UnavailableOffline";
            }
            else if ((m_Current_Temperature < 0) || ((m_Current_Temperature >= m_Warning) && (m_Current_Temperature < m_Error)))
            {
                //     Area : 1 / 3
                m_Status_Health = "Warning";
                m_Status_State = "Enabled";

                std::string event("Event");
                std::string servrity("Warning");
                std::string sensor_type("Temperature");
                std::string message;
                message = std::string("PSU Thermal is ") + std::to_string(m_Current_Temperature / 1000) + std::string(" degrees.Over warning temperature.");
                gADbg.acc_printf("set_info-----PSU_Sensor-----Warning--\r\n");

                std::string message_event = std::string("PSU Thermal ") + std::to_string(ID) + std::string(" is ") + std::to_string(m_Current_Temperature / 1000) + std::string(" degrees.  Over warning temperature.");

                if (m_psu_thermal_alert != 1)
                {
                    m_Event_Resouce_Alert.push_back(message_event);
                    m_psu_thermal_alert = 1;
                }
            }
            else if (((m_Current_Temperature >= m_Error)) && (m_Current_Temperature < m_Shutdown))
            {
                //     Area : 4

                m_Status_Health = "Warning";
                m_Status_State = "Enabled";

                std::string event("Event");
                std::string servrity("Warning");
                std::string sensor_type("Temperature");
                std::string message;
                message = std::string("PSU Thermal is ") + std::to_string(m_Current_Temperature / 1000) + std::string(" degrees.Over error temperature.");
                gADbg.acc_printf("set_info-----PSU_Sensor-----Warning--\r\n");

                std::string message_event = std::string("PSU Thermal ") + std::to_string(ID) + std::string(" is ") + std::to_string(m_Current_Temperature / 1000) + std::string(" degrees.  Over error temperature.");

                if (m_psu_thermal_alert != 4)
                {
                    m_Event_Resouce_Alert.push_back(message_event);
                    m_psu_thermal_alert = 4;
                }
            }
            else if ((m_Current_Temperature >= m_Shutdown))
            {
                //     Area : 5
                m_Status_Health = "Critical";
                m_Status_State = "Enabled";

                std::string event("Event");
                std::string servrity("Warning");
                std::string sensor_type("Temperature");
                std::string message;
                message = std::string("PSU Thermal is ") + std::to_string(m_Current_Temperature / 1000) + std::string(" degrees.Over fatal temperature.");
                gADbg.acc_printf("set_info-----PSU_Sensor-----Critical--\r\n");

                std::string message_event = std::string("PSU Thermal ") + std::to_string(ID) + std::string(" is ") + std::to_string(m_Current_Temperature / 1000) + std::string(" degrees.  Over fatal temperature.");

                if (m_psu_thermal_alert != 5)
                {
                    m_Event_Resouce_Alert.push_back(message_event);
                    m_psu_thermal_alert = 5;
                }
            }
            else
            {
                //     Area : 2

                m_Status_Health = "OK";
                m_Status_State = "Enabled";
                m_psu_thermal_alert = 0;
            }
        }
        else
        {
            m_Status_Health = "Warning";
            m_Status_State = "Absent";
        }

        return;
    }
    catch (const std::exception &e)
    {
        std::cout << "Thermal_Info set_info() - exception : " << e.what() << std::endl;
        return;
    }
}

void Port_Info::set_info(int ID, int Type, int Present_Status, bool present)
{
    m_ID = ID;
    m_Type = Type;
    m_Present_Status = Present_Status;
    m_Present = present;
}

void Port_Info::set_tx(bool status, std::string in_tx_sys_path)
{
#if 0
    std::string tx_sys_path = in_tx_sys_path; 
    std::ofstream os;
    printf("set_tx[%s] status[%d]\r\n", tx_sys_path.c_str(), status);
    try
    {
        if (os)
        {
            os.open(tx_sys_path);
            if (status == false)
                os << 1;
            else
                os << 0;
            os.close();
        }
        else
        {
            std::cout << "sysfile open error" << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "set tx exception : " << e.what() << std::endl;
    }
#else
    UNUSED(in_tx_sys_path);
    try
    {
        int value;
        if (status == false)
            value = 1;
        else
            value = 0;
        std::cout << "Port Id is " << m_ID - 1 << std::endl;
        onlp_sfp_control_set(m_ID - 1, ONLP_SFP_CONTROL_TX_DISABLE, value);
        std::cout << "TX_Disable set " << value << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "set tx exception : " << e.what() << std::endl;
    }
#endif
}

int Port_Info::get_tx_status(std::string in_tx_sys_path)
{
#if 0
    std::string tx_sys_path = in_tx_sys_path;
    printf("get_tx_status[%s]\r\n", tx_sys_path.c_str());
    std::ifstream is;
    char stor[2];
    is.rdbuf()->pubsetbuf(0, 0); // do not buffer //
    try
    {
        if (is)
        {
            is.open(tx_sys_path);
            is.read((char *)stor, sizeof(stor));
            if (is.is_open() && atoi(stor) == 0)
            {
                is.close();
                return 0;
            }
            else
            {
                is.close();
                return 1;
            }
        }
        else
        {
            std::cout << "sysfile open error" << std::endl;
            return -1;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "get tx status exception : " << e.what() << std::endl;
        return -1;
    }
#else
    UNUSED(in_tx_sys_path);
    try
    {
        int value;
        std::cout << "Port Id is " << m_ID - 1 << std::endl;
        onlp_sfp_control_get(m_ID - 1, ONLP_SFP_CONTROL_TX_DISABLE, &value);
        std::cout << "TX_Disable get " << value << std::endl;
        return value;
    }
    catch (const std::exception &e)
    {
        std::cout << "get tx status exception : " << e.what() << std::endl;
        return -1;
    }
#endif
}

void Acc_Switch::get_psu_info()
{
    try
    {
        int rv;
        onlp_psu_info_t fv;
        int ii = 0;

        for (ii = 1; ii <= get_psu_num(); ii++)
        {
            unsigned int id = ONLP_PSU_ID_CREATE(ii);
            rv = onlp_psu_info_get(id, &fv);

            gADbg.acc_printf("/////////////////////\r\n");

            for (vector<Psu_Info *>::iterator pObj = m_vec_Psu_Info.begin(); pObj != m_vec_Psu_Info.end(); ++pObj)
            {
                if (rv < 0 && (*pObj)->m_ID == ii)
                {
                    set_psu_present(ii, false);
                    gADbg.acc_printf("get_psu_info [%d] error\r\n", ii);
                }
                else
                {
                    if ((*pObj)->m_ID == ii)
                    {
                        if (fv.status & 1)
                        {
                            unsigned int caps = fv.caps;
                            Psu_Info::onlp_psu_type_t psu_type = Psu_Info::ONLP_PSU_TYPE_INVALID;

                            if (caps & Psu_Info::ONLP_PSU_CAPS_AC)
                                psu_type = Psu_Info::ONLP_PSU_TYPE_AC;
                            else if (caps & Psu_Info::ONLP_PSU_CAPS_DC12)
                                psu_type = Psu_Info::ONLP_PSU_TYPE_DC12;
                            else if (caps & Psu_Info::ONLP_PSU_CAPS_DC48)
                                psu_type = Psu_Info::ONLP_PSU_TYPE_DC48;

                            set_psu_present(ii, true);
                            (*pObj)->set_info(ii, fv.model[0] ? fv.model : "NULL", fv.serial[0] ? fv.serial : "NULL", fv.mvin, fv.mvout, fv.miin, fv.miout, fv.mpin, fv.mpout, psu_type, true);
                            gADbg.acc_printf("s psu ID:  %d\r\n", (*pObj)->m_ID);
                            gADbg.acc_printf("s psu Model:  %s\r\n", (*pObj)->m_Model.c_str());
                            gADbg.acc_printf("s psu SN:  %s\r\n", (*pObj)->m_SN.c_str());
                            gADbg.acc_printf("s psu Vin:  %d\r\n", (*pObj)->m_Vin);
                            gADbg.acc_printf("s psu Vout:  %d\r\n", (*pObj)->m_Vout);
                            gADbg.acc_printf("s psu Iin:  %d\r\n", (*pObj)->m_Iin);
                            gADbg.acc_printf("s psu Iout:  %d\r\n", (*pObj)->m_Iout);
                            gADbg.acc_printf("s psu Pin:  %d\r\n", (*pObj)->m_Pin);
                            gADbg.acc_printf("s psu Pout:  %d\r\n", (*pObj)->m_Pout);
                            gADbg.acc_printf("s psu Type:  %d\r\n", (*pObj)->m_Psu_Type);
                        }
                        else
                        {
                            set_psu_present(ii, false);
                            (*pObj)->set_info(ii, "NULL", "NULL", 0, 0, 0, 0, 0, 0, Psu_Info::ONLP_PSU_TYPE_INVALID, false);
                            gADbg.acc_printf("PSU [%d] Not present.\r\n", ii);
                        }
                    }
                }
            }
        }
        gADbg.acc_printf("PSU PRESNET [0x%04x]\r\n\r\n", get_psu_present());
        gADbg.acc_printf("/////////////////////\r\n");
        return;
    }
    catch (const std::exception &e)
    {
        std::cout << "Acc_Switch get_psu_info() - exception : " << e.what() << std::endl;
        return;
    }
}

int Acc_Switch::get_psu_info_by_(int psuid, Psu_Content id)
{
    try
    {
        int ii = 0;

        for (ii = 1; ii <= get_psu_num(); ii++)
        {
            for (vector<Psu_Info *>::iterator pObj = m_vec_Psu_Info.begin(); pObj != m_vec_Psu_Info.end(); ++pObj)
            {
                if ((*pObj)->m_ID == psuid)
                {
                    switch (id)
                    {
                    case Vin:
                        return (*pObj)->m_Vin;
                        break;
                    case Vout:
                        return (*pObj)->m_Vout;
                        break;
                    case Iin:
                        return (*pObj)->m_Iin;
                        break;
                    case Iout:
                        return (*pObj)->m_Iout;
                        break;
                    case Pin:
                        return (*pObj)->m_Pin;
                        break;
                    case Pout:
                        return (*pObj)->m_Pout;
                        break;
                    case Psu_type:
                        return (*pObj)->m_Psu_Type;
                        break;
                    case Psu_Present:
                        return (*pObj)->m_Present;
                        break;
                    default:
                        return 0;
                        break;
                    }
                }
            }
        }
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cout << "Acc_Switch get_psu_info_by_() - exception : " << e.what() << std::endl;
        return 0;
    }
}

std::string Acc_Switch::get_psu_info_by_(int psuid, std::string type)
{
    try
    {
        int ii = 0;

        for (ii = 1; ii <= get_psu_num(); ii++)
        {
            for (vector<Psu_Info *>::iterator pObj = m_vec_Psu_Info.begin(); pObj != m_vec_Psu_Info.end(); ++pObj)
            {
                if ((*pObj)->m_ID == psuid)
                {
                    if (type == "Status_Health")
                        return (*pObj)->m_Status_Health;
                    else if (type == "Status_State")
                        return (*pObj)->m_Status_State;
                    else if (type == "Model")
                        return (*pObj)->m_Model;
                    else if (type == "SN")
                        return (*pObj)->m_SN;
                    else
                        return "na";
                }
            }
        }

        return "na";
    }
    catch (const std::exception &e)
    {
        std::cout << "Acc_Switch string get_psu_info_by_() - exception : " << e.what() << std::endl;
        return "na";
    }
}

std::string Acc_Switch::get_thermal_info_by_(int thermalid, std::string type)
{
    try
    {
        int ii = 0;

        for (ii = 1; ii <= get_thermal_num(); ii++)
        {
            for (vector<Thermal_Info *>::iterator pObj = m_vec_Thermal_Info.begin(); pObj != m_vec_Thermal_Info.end(); ++pObj)
            {
                if ((*pObj)->m_ID == thermalid)
                {
                    if (type == "Status_Health")
                        return (*pObj)->m_Status_Health;
                    else if (type == "Status_State")
                        return (*pObj)->m_Status_State;
                    else
                        return "na";
                }
            }
        }

        return "na";
    }
    catch (const std::exception &e)
    {
        std::cout << "Acc_Switch string get_thermal_info_by_() - exception : " << e.what() << std::endl;
        return "na";
    }
}

int Acc_Switch::get_thermal_info_by_(int thermalid, Thermal_Content id)
{
    try
    {
        int ii = 0;

        for (ii = 1; ii <= get_thermal_num(); ii++)
        {
            for (vector<Thermal_Info *>::iterator pObj = m_vec_Thermal_Info.begin(); pObj != m_vec_Thermal_Info.end(); ++pObj)
            {
                if ((*pObj)->m_ID == thermalid)
                {
                    switch (id)
                    {
                    case Current_Temperature:
                        return (*pObj)->m_Current_Temperature;
                        break;
                    case Warning:
                        return (*pObj)->m_Warning;
                        break;
                    case Error:
                        return (*pObj)->m_Error;
                        break;
                    case Shutdown:
                        return (*pObj)->m_Shutdown;
                        break;
                    case Thermal_Type:
                        return (*pObj)->m_Type;
                        break;
                    case Thermal_Present:
                        return (*pObj)->m_Present;
                        break;
                    default:
                        return 0;
                        break;
                    }
                }
            }
        }
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cout << "Acc_Switch  get_thermal_info_by_() - exception : " << e.what() << std::endl;
        return 0;
    }
}

int Acc_Switch::get_port_info_by_(int portid, Port_Content id)
{
    try
    {
        std::lock_guard<std::mutex> lock{m_data_mutex};

        int ii = 0;

        for (ii = 1; ii <= m_port_max_num; ii++)
        {
            for (vector<Port_Info *>::iterator pObj = m_vec_Port_Info.begin(); pObj != m_vec_Port_Info.end(); ++pObj)
            {
                if ((*pObj)->m_ID == portid)
                {
                    switch (id)
                    {
                    case Port_Present:
                        if ((*pObj)->m_Type == Port_Info::Ether_Port)
                            return true;
                        else
                            return (*pObj)->m_Present_Status;
                        break;
                    case Port_Type:
                        return (*pObj)->m_Type;
                        break;
                    default:
                        return 0;
                        break;
                    }
                }
            }
        }
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cout << "Acc_Switch get_port_info_by_() - exception : " << e.what() << std::endl;
        return 0;
    }
}

json::Value Acc_Switch::get_port_trans_info_by_(int portid)
{
    try
    {
        std::lock_guard<std::mutex> lock{m_data_mutex};

        int ii = 0;

        for (ii = 1; ii <= m_port_max_num; ii++)
        {
            for (vector<Port_Info *>::iterator pObj = m_vec_Port_Info.begin(); pObj != m_vec_Port_Info.end(); ++pObj)
            {
                if ((*pObj)->m_ID == portid)
                {
                    return (*pObj)->get_trans_status();
                }
            }
        }
        return json::Value::Type::NIL;
    }
    catch (const std::exception &e)
    {
        std::cout << "Acc_Switch get_port_trans_info_by_() - exception : " << e.what() << std::endl;
        return json::Value::Type::NIL;
    }
}

void Acc_Switch::update_transceivers_oom_event()
{
    try
    {
        std::lock_guard<std::mutex> lock{m_data_mutex};

        int ii = 0;

        for (ii = 1; ii <= m_port_max_num; ii++)
        {
            for (vector<Port_Info *>::iterator pObj = m_vec_Port_Info.begin(); pObj != m_vec_Port_Info.end(); ++pObj)
            {
                (*pObj)->get_trans_status(); //todo //
            }
        }
        return;
    }
    catch (const std::exception &e)
    {
        std::cout << "Acc_Switch update_transceivers_oom_event() - exception : " << e.what() << std::endl;
        return;
    }
}

void Acc_Switch::update_port_present_event()
{
    try
    {
        int id = 0;

        for (id = 0; id < m_port_max_num; id++)
        {
            if (id < 64)
            {
                // Check port present //
                unsigned long long m_bit = (1ULL << id);
                int p_bit = ((m_pre_Port_Present & m_bit) >> id);
                int c_bit = ((m_Port_Present & m_bit) >> id);

                if ((p_bit == 1) && (c_bit == 0))
                { // port unplug
                    std::string event("Event");
                    std::string servrity("OK");
                    std::string sensor_type("Entity Presence");
                    std::string message("Port unplug.");

                    std::string message_event = std::string("Port ") + std::to_string(id + 1) + std::string(" Plug Out.");
                    m_Event_Port_Resouce_Remove.push_back(message_event);
                }
                else if ((p_bit == 0) && (c_bit == 1))
                { // port plug in
                    std::string event("Event");
                    std::string servrity("OK");
                    std::string sensor_type("Entity Presence");
                    std::string message("Port plug in.");

                    std::string message_event = std::string("Port ") + std::to_string(id + 1) + std::string(" Plug In.");
                    m_Event_Port_Resouce_Add.push_back(message_event);
                }
            }
            else if ((id >= 64) && (id < 128))
            {
                int A64_id = id - 64;

                // Check port present //
                unsigned long long m_bit = (1ULL << A64_id);
                unsigned long long p_bit = ((m_pre_Port_Present_A64 & m_bit) >> A64_id);
                unsigned long long c_bit = ((m_Port_Present_A64 & m_bit) >> A64_id);

                if ((p_bit == 1) && (c_bit == 0))
                { // port unplug
                    std::string event("Event");
                    std::string servrity("OK");
                    std::string sensor_type("Entity Presence");
                    std::string message("Port unplug.");

                    std::string message_event = std::string("Port ") + std::to_string(id + 1) + std::string(" Plug Out.");
                    m_Event_Port_Resouce_Remove.push_back(message_event);
                }
                else if ((p_bit == 0) && (c_bit == 1))
                { // port plug in
                    std::string event("Event");
                    std::string servrity("OK");
                    std::string sensor_type("Entity Presence");
                    std::string message("Port plug in.");

                    std::string message_event = std::string("Port ") + std::to_string(id + 1) + std::string(" Plug In.");
                    m_Event_Port_Resouce_Add.push_back(message_event);
                }
            }
            else
            {
                printf("Port chceking more then 128 port!!!!not enough bits to present\r\n\r\n");
            }
        }

        m_pre_Port_Present = m_Port_Present;
        m_pre_Port_Present_A64 = m_Port_Present_A64;

        return;
    }
    catch (const std::exception &e)
    {
        std::cout << "Acc_Switch update_port_present_event() - exception : " << e.what() << std::endl;
        return;
    }
}

void Acc_Switch::update_psu_present_event()
{
    try
    {
        int id = 0;

        for (id = 0; id < get_psu_num(); id++)
        {

            // Check PSU present //
            unsigned int m_bit = (1 << id);
            unsigned int p_bit = ((m_pre_Psu_Present & m_bit) >> id);
            unsigned int c_bit = ((m_Psu_Present & m_bit) >> id);

            if ((p_bit == 1) && (c_bit == 0))
            { // PSU unplug
                std::string event("Event");
                std::string servrity("OK");
                std::string sensor_type("Power Supply / Converter");
                std::string message("PSU unplug.");

                std::string message_event = std::string("PSU ") + std::to_string(id + 1) + std::string(" Plug Out.");
                m_Event_Resouce_Remove.push_back(message_event);
            }
            else if ((p_bit == 0) && (c_bit == 1))
            { // PSU plug in
                std::string event("Event");
                std::string servrity("OK");
                std::string sensor_type("Power Supply / Converter");
                std::string message("PSU plug in.");

                std::string message_event = std::string("PSU ") + std::to_string(id + 1) + std::string(" Plug In.");
                m_Event_Resouce_Add.push_back(message_event);
            }
        }
        m_pre_Psu_Present = m_Psu_Present;

        return;
    }
    catch (const std::exception &e)
    {
        std::cout << "Acc_Switch update_psu_present_event() - exception : " << e.what() << std::endl;
        return;
    }
}

void Acc_Switch::get_fan_info()
{
    try
    {
        int rv;
        onlp_fan_info_t fv;
        int ii = 0;

        gADbg.acc_printf("get_fan_info m_fan_max_num[%d]/////////////////////\r\n", get_fan_num());

        for (ii = 1; ii <= get_fan_num(); ii++)
        {
            unsigned int id = ONLP_FAN_ID_CREATE(ii);
            rv = onlp_fan_info_get(id, &fv);

            gADbg.acc_printf("get_fan_info [%d]/////////////////////\r\n", ii);

            for (vector<Fan_Info *>::iterator pObj = m_vec_Fan_Info.begin(); pObj != m_vec_Fan_Info.end(); ++pObj)
            {
                if (rv < 0 && (*pObj)->m_ID == ii)
                {
                    set_fan_present(ii, false);
                    (*pObj)->set_info(ii, fv.model[0] ? fv.model : "NULL", fv.serial[0] ? fv.serial : "NULL", 0, 0, false);
                    gADbg.acc_printf("get_fan_info [%d] error\r\n", ii);
                }
                else if ((*pObj)->m_ID == ii)
                {
                    if (fv.status & 1)
                    {
                        set_fan_present(ii, true);
                        (*pObj)->set_info(ii, fv.model[0] ? fv.model : "NULL", fv.serial[0] ? fv.serial : "NULL", fv.rpm, fv.percentage, true);
                        gADbg.acc_printf("s fan fan[%d]\r\n", (*pObj)->m_ID);
                        gADbg.acc_printf("s fan RPM:    %d\r\n", (*pObj)->m_RPM);
                        gADbg.acc_printf("s fan Per:    %d\r\n", (*pObj)->m_Per);
                        gADbg.acc_printf("s fan Model:  %s\r\n", (*pObj)->m_Model.c_str());
                        gADbg.acc_printf("s fan SN:     %s\r\n", (*pObj)->m_SN.c_str());
                        /* Present */
                    }
                    else
                    {
                        set_fan_present(ii, false);
                        (*pObj)->set_info(ii, "NULL", "NULL", 0, 0, false);
                        gADbg.acc_printf("FAN [%d] Not present.\r\n", ii);
                    }
                }
            }
        }
        gADbg.acc_printf("FAN PRESNET [0x%04x]\r\n\r\n", get_fan_present());
        gADbg.acc_printf("/////////////////////\r\n");
    }
    catch (const std::exception &e)
    {
        std::cout << "Acc_Switch get_fan_info() - exception : " << e.what() << std::endl;
        return;
    }
}

int Acc_Switch::get_fan_info_by_(int fanid, Fan_Content id)
{
    try
    {
        int ii = 0;

        for (ii = 1; ii <= get_fan_num(); ii++)
        {
            for (vector<Fan_Info *>::iterator pObj = m_vec_Fan_Info.begin(); pObj != m_vec_Fan_Info.end(); ++pObj)
            {
                if ((*pObj)->m_ID == fanid)
                {
                    switch (id)
                    {
                    case RPM:
                        return (*pObj)->m_RPM;
                        break;
                    case Per:
                        return (*pObj)->m_Per;
                        break;
                    case Type:
                        return (*pObj)->m_Type;
                        break;
                    case Fan_Present:
                        return (*pObj)->m_Present;
                        break;

                    default:
                        return 0;
                        break;
                    }
                }
            }
        }
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cout << "Acc_Switch get_fan_info_by_() - exception : " << e.what() << std::endl;
        return 0;
    }
}

std::string Acc_Switch::get_fan_info_by_(int fanid, std::string type)
{
    try
    {
        int ii = 0;

        for (ii = 1; ii <= get_fan_num(); ii++)
        {
            for (vector<Fan_Info *>::iterator pObj = m_vec_Fan_Info.begin(); pObj != m_vec_Fan_Info.end(); ++pObj)
            {
                if ((*pObj)->m_ID == fanid)
                {
                    if (type == "Status_Health")
                        return (*pObj)->m_Status_Health;
                    else if (type == "Status_State")
                        return (*pObj)->m_Status_State;
                    else
                        return "na";
                }
            }
        }
        return "na";
    }
    catch (const std::exception &e)
    {
        std::cout << "Acc_Switch string get_fan_info_by_() - exception : " << e.what() << std::endl;
        return "na";
    }
}

void Acc_Switch::update_fan_present_event()
{
    try
    {
        int id = 0;

        for (id = 0; id < get_fan_num(); id++)
        {
            // Check FAN present //
            unsigned long long m_bit = (1 << id);
            unsigned long long p_bit = ((m_pre_Fan_Present & m_bit) >> id);
            unsigned long long c_bit = ((m_Fan_Present & m_bit) >> id);

            if ((p_bit == 1) && (c_bit == 0))
            { // FAN unplug
                std::string event("Event");
                std::string servrity("OK");
                std::string sensor_type("Fan");
                std::string message("FAN unplug.");

                std::string message_event = std::string("Fan ") + std::to_string(id + 1) + std::string(" Plug Out.");
                m_Event_Resouce_Remove.push_back(message_event);
            }
            else if ((p_bit == 0) && (c_bit == 1))
            { // FAN plug in
                std::string event("Event");
                std::string servrity("OK");
                std::string sensor_type("Fan");
                std::string message("FAN plug in.");

                std::string message_event = std::string("Fan ") + std::to_string(id + 1) + std::string(" Plug In.");
                m_Event_Resouce_Add.push_back(message_event);
            }
        }
        m_pre_Fan_Present = m_Fan_Present;

        return;
    }
    catch (const std::exception &e)
    {
        std::cout << "Acc_Switch update_fan_present_event() - exception : " << e.what() << std::endl;
        return;
    }
}

void Acc_Switch::update_thermal_present_event()
{
    try
    {
        int id = 0;

        for (id = 0; id < get_thermal_num(); id++)
        {

            // Check Thermal present //
            unsigned int m_bit = (1 << id);
            unsigned int p_bit = ((m_pre_Thermal_Present & m_bit) >> id);
            unsigned int c_bit = ((m_Thermal_Present & m_bit) >> id);

            if ((p_bit == 1) && (c_bit == 0))
            { // Thermal unplug
                std::string event("Event");
                std::string servrity("OK");
                std::string sensor_type("Thermal");
                std::string message("Thermal sensor unplug.");
            }
            else if ((p_bit == 0) && (c_bit == 1))
            { // Thermal Thermal in
                std::string event("Event");
                std::string servrity("OK");
                std::string sensor_type("Thermal");
                std::string message("Thermal sensor plug in.");
            }
        }
        m_pre_Thermal_Present = m_Thermal_Present;

        return;
    }
    catch (const std::exception &e)
    {
        std::cout << "Acc_Switch update_thermal_present_event() - exception : " << e.what() << std::endl;
        return;
    }
}

void Acc_Switch::get_basic_info()
{
    try
    {
        int rv;
        onlp_init();
        //Collect PSU/THERMAL/FAN number
        onlp_oid_iterate(ONLP_OID_SYS, ONLP_OID_TYPE_PSU, iterate_oids_callback__, NULL);
        onlp_oid_iterate(ONLP_OID_SYS, ONLP_OID_TYPE_THERMAL, iterate_oids_callback__, NULL);
        onlp_oid_iterate(ONLP_OID_SYS, ONLP_OID_TYPE_FAN, iterate_oids_callback__, NULL);

        onlp_sys_info_t si;
        rv = onlp_sys_info_get(&si);
        if (rv < 0)
        {
            gADbg.acc_printf("error-get_basic_info\r\n");
            return;
        }
        else
        {
            onlp_onie_info_t *info = &si.onie_info;

            if (info->product_name)
                m_Product_Name = info->product_name;

            if (info->part_number)
                m_Part_Number = info->part_number;

            if (info->serial_number)
                m_Serial_Number = info->serial_number;

            memcpy(this->m_MAC, info->mac, 6);

            if (info->mac_range)
                m_MAC_Range = info->mac_range;

            if (info->manufacturer)
                m_Manufacturer = info->manufacturer;

            if (info->manufacture_date)
                m_Manu_Date = info->manufacture_date;

            if (info->vendor)
                m_Vendor = info->vendor;

            if (info->platform_name)
                m_Platform_Name = info->platform_name;

            if (info->device_version)
                m_Device_Version = info->device_version;

            if (info->label_revision)
                m_Label_Revision = info->label_revision;

            if (info->country_code)
                m_Country_Code = info->country_code;

            if (info->diag_version)
                m_Diag_Version = info->diag_version;

            if (info->service_tag)
                m_Service_Tag = info->service_tag;

            if (info->onie_version)
                m_ONIE_Version = info->onie_version;

            gADbg.acc_printf("Product Name: %s\r\n", info->product_name);
            gADbg.acc_printf("Part Number: %s\r\n", info->part_number);
            gADbg.acc_printf("Serial Number: %s\r\n", info->serial_number);
            gADbg.acc_printf("MAC: [0x%02x:0x%02x:0x%02x:0x%02x:0x%02x:0x%02x:\r\n", info->mac[0], info->mac[1], info->mac[2], info->mac[3], info->mac[4], info->mac[5]);
            gADbg.acc_printf("MAC Range: %d\r\n", info->mac_range);
            gADbg.acc_printf("Manufacturer: %s\r\n", info->manufacturer);
            gADbg.acc_printf("Manufacture Date: %s\r\n", info->manufacture_date);
            gADbg.acc_printf("Vendor: %s\r\n", info->vendor);
            gADbg.acc_printf("Platform Name: %s\r\n", info->platform_name);
            gADbg.acc_printf("Device Version: %u\r\n", info->device_version);
            gADbg.acc_printf("Label Revision: %s\r\n", info->label_revision);
            gADbg.acc_printf("Country Code: %s\r\n", info->country_code);
            gADbg.acc_printf("Diag Version: %s\r\n", info->diag_version);
            gADbg.acc_printf("Service Tag: %s\r\n", info->service_tag);
            gADbg.acc_printf("ONIE Version: %s\r\n", info->onie_version);

            onlp_sys_info_free(&si);
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Acc_Switch get_basic_info() - exception : " << e.what() << std::endl;
        return;
    }
}

Acc_Switch::~Acc_Switch()
{
    for (vector<Thermal_Info *>::iterator pObj = m_vec_Thermal_Info.begin(); pObj != m_vec_Thermal_Info.end(); ++pObj)
    {
        delete *pObj;
    }

    for (vector<Psu_Info *>::iterator pObj = m_vec_Psu_Info.begin(); pObj != m_vec_Psu_Info.end(); ++pObj)
    {
        delete *pObj;
    }

    for (vector<Fan_Info *>::iterator pObj = m_vec_Fan_Info.begin(); pObj != m_vec_Fan_Info.end(); ++pObj)
    {
        delete *pObj;
    }

    for (vector<Port_Info *>::iterator pObj = m_vec_Port_Info.begin(); pObj != m_vec_Port_Info.end(); ++pObj)
    {
        delete *pObj;
    }
}

Acc_Switch &Acc_Switch::get_instance()
{
    try
    {
        if (NULL == g_Switch)
        {
            ifstream ifs("/etc/onl/platform");
            std::string s;
            getline(ifs, s, (char)ifs.eof());
            printf("Creating platform [%s] size[%d]\r\n", s.c_str(), (int)s.size());

            if (s.find("asxvolt16", 0) != std::string::npos)
            {
                printf("x86-64-accton-asxvolt16\r\n");
                g_Switch = new Asxvolt16();
            }
            else if (s.find("asgvolt64", 0) != std::string::npos)
            {
                printf("x86-64-accton-asgvolt64\r\n");
                g_Switch = new Asgvolt64();
            }
            else if (s.find("as5916-54xks", 0) != std::string::npos)
            {
                printf("x86-64-accton-as5916-54xks\r\n");
                g_Switch = new As5916_54xks();
            }
            else if (s.find("as5916-54xk", 0) != std::string::npos)
            {
                printf("x86-64-accton-as5916-54xk\r\n");
                g_Switch = new As5916_54xk();
            }
            else
            {
                printf("x86-64-accton-generic\r\n");
                g_Switch = new Acc_Switch();
            }
        }
        return *g_Switch;
    }
    catch (const std::exception &e)
    {
        std::cout << "Acc_Switch get_basic_info() - exception : " << e.what() << std::endl;
        return *g_Switch;
    }
}

void Acc_Switch::get_per_port_sys_file()
{
    try
    {
        Json::Value mapping_s;
        Json::Reader onulist_j_reader = {};
        std::string mapping_file_path = PORT_MAP_PATH + m_onl_platinfo_name + "-sysfs";
        printf("get_per_port_sys_file() mapping_file_path[%s]\r\n", mapping_file_path.c_str());

        std::ifstream map_files(mapping_file_path);

        bool isJson = (onulist_j_reader.parse(map_files, mapping_s));

        if (isJson)
        {
            printf("Get sys_fs mapping file ok!!\r\n");
            int ii = 0;
            for (ii = 1; ii <= m_port_max_num; ii++)
            {
                for (vector<Port_Info *>::iterator pObj = m_vec_Port_Info.begin(); pObj != m_vec_Port_Info.end(); ++pObj)
                {
                    if ((*pObj)->m_ID == ii)
                    {
                        (*pObj)->set_sysfile_path(mapping_s[std::to_string(ii)].asString());
                        break;
                    }
                }
            }
        }
        else
            printf("Get sys fs mapping file error!!\r\n");
    }
    catch (const std::exception &e)
    {
        std::cout << "Acc_Switch get_per_port_sys_file() - exception : " << e.what() << std::endl;
    }
}

std::vector<std::string> Dev_Info::m_Event_Resouce_Alert = {};

std::vector<std::string> Dev_Info::m_Event_Port_Resouce_Alert = {};

std::vector<std::string> Dev_Info::get_Event_Resouce_Alert()
{
    return m_Event_Resouce_Alert;
}

void Dev_Info::Clear_Event_Resouce_Alert()
{
    m_Event_Resouce_Alert.clear();
    return;
}

void Dev_Info::Clear_Event_Port_Resouce_Alert()
{
    m_Event_Port_Resouce_Alert.clear();
    return;
}

std::vector<std::string> Acc_Switch::m_Event_Resouce_Add = {};

std::vector<std::string> Acc_Switch::get_Event_Resouce_Add()
{
    return m_Event_Resouce_Add;
}

std::vector<std::string> Acc_Switch::m_Event_Port_Resouce_Add = {};

std::vector<std::string> Acc_Switch::get_Event_Port_Resouce_Add()
{
    return m_Event_Port_Resouce_Add;
}

std::vector<std::string> Acc_Switch::m_Event_Resouce_Remove = {};

std::vector<std::string> Acc_Switch::get_Event_Resouce_Remove()
{
    return m_Event_Resouce_Remove;
}

std::vector<std::string> Acc_Switch::m_Event_Port_Resouce_Remove = {};

std::vector<std::string> Acc_Switch::get_Event_Port_Resouce_Remove()
{
    return m_Event_Port_Resouce_Remove;
}

std::vector<std::string> Acc_Switch::get_Event_Resouce_Alert()
{
    return Dev_Info::get_Event_Resouce_Alert();
}

std::vector<std::string> Acc_Switch::get_Event_Port_Resouce_Alert()
{
    return Dev_Info::get_Event_Resouce_Alert();
}

void Acc_Switch::clean_Event_Resource_Event()
{
    m_Event_Resouce_Add.clear();
    m_Event_Resouce_Remove.clear();
    Dev_Info::Clear_Event_Resouce_Alert();
    return;
}

void Acc_Switch::clean_Event_Port_Resource_Event()
{
    m_Event_Port_Resouce_Add.clear();
    m_Event_Port_Resouce_Remove.clear();
    Dev_Info::Clear_Event_Port_Resouce_Alert();
    return;
}
} // namespace acc_onlp_helper
