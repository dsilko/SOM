/* Copyright 2018 Denis Silko. All rights reserved.
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 http:www.apache.org/licenses/LICENSE-2.0
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#ifndef weight_distance_kernel_hpp
#define weight_distance_kernel_hpp

#include "kernel.hpp"

namespace som {
    
    class Model;
    
    class WeightDistanceKernel : private Kernel {
        
    public:
        WeightDistanceKernel(const std::string code, const std::string name, cl_context &context, cl_command_queue &commandQueue, cl_device_id &deviceId);
        
        void connect(const Model &, const cl_mem &inputBuffer, const cl_mem &weightsBuffer, const cl_mem &distancesBuffer);
        void compute(const cl_float &vector);
        
    private:
        cl_mem inputBuffer_;
        cl_mem weightsBuffer_;
        cl_mem distancesBuffer_;
        
        size_t channels_, nodesCount_;
        cl_float *weights_, *distances_;
        
    };
    
}

#endif /* weight_distance_kernel_hpp */
