#!/bin/bash

CUR_PATH=$(cd "$(dirname "$0")"; pwd)
PROJ_PATH=$CUR_PATH/../../../../
PSME_PROJ_PATH=$CUR_PATH/../../../
PSME_ACC_NETWORK_SW_DIR="$PROJ_PATH/agent/acc_network/acc_sw"
PSME_ACC_SCRIPT_DIR="$PSME_ACC_NETWORK_SW_DIR/acc_script"

LIB_PREINSTALL=/usr/lib/x86_64-linux-gnu

function del_file()
{
    for del in $1*
    do
        if [ -f $del ]
        then
            rm -rf $del
        fi
    done
}

ITEM_PATH=$CUR_PATH/../psme-allinone

mkdir -p $ITEM_PATH/usr/local/bin
mkdir -p $ITEM_PATH/usr/local/sbin
mkdir -p $ITEM_PATH/usr/local/lib
mkdir -p $ITEM_PATH/etc
mkdir -p $ITEM_PATH/etc/logrotate.d

del_file $ITEM_PATH/usr/local/bin/
del_file $ITEM_PATH/usr/local/lib/
del_file $ITEM_PATH/etc/

mkdir -p $ITEM_PATH/etc/psme/certs   
chmod 700 $ITEM_PATH/etc/psme/certs
mkdir -p $ITEM_PATH/broadcom   

cp ${PSME_ACC_NETWORK_SW_DIR}/certs/*                     $ITEM_PATH/etc/psme/certs
cp ${PSME_ACC_NETWORK_SW_DIR}/*                           $ITEM_PATH/etc/psme/
cp -rf ${PSME_ACC_NETWORK_SW_DIR}/mod_conf                $ITEM_PATH/etc/psme/

cp $PSME_PROJ_PATH/bin/psme-rest-server                   $ITEM_PATH/usr/local/bin
cp $PSME_PROJ_PATH/bin/acc-psme-chassis                   $ITEM_PATH/usr/local/bin
cp $PSME_PROJ_PATH/bin/tests/unittest_psme-chassis_onlp   $ITEM_PATH/usr/local/bin
cp $PSME_ACC_SCRIPT_DIR/*                                 $ITEM_PATH/usr/local/bin

$CUR_PATH/modify_ver.sh $ITEM_PATH
