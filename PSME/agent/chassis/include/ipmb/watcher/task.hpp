/*!
 * @copyright
 * Copyright (c) 2015-2019 Intel Corporation
 *
 * @copyright
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * @copyright
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * @copyright
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @file ipmb/watcher/task.hpp
 * @brief IPMB watcher task.
 * */

#pragma once
#include <memory>

/*! Agent namspace */
namespace agent {
/*! Chassis namspace */
namespace chassis {
/*! IPMB namspace */
namespace ipmb {
/*! Watcher namspace */
namespace watcher {

/*! IPMB watcher task interface*/
class Task {
public:
    virtual ~Task();

    /*! Executes task */
    virtual void execute() = 0;
};

/*! IPMB watcher task shared pointer */
using TaskSPtr = std::shared_ptr<Task>;

}
}
}
}

