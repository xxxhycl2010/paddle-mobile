/* Copyright (c) 2018 PaddlePaddle Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */

#ifdef TRANSPOSE_OP

#pragma once

#include <string>

#include "framework/operator.h"
#include "operators/kernel/transpose_kernel.h"
#include "operators/op_param.h"

namespace paddle_mobile {
namespace operators {

using paddle_mobile::framework::Tensor;

template <typename DeviceType, typename T>
class TransposeOp : public framework::OperatorWithKernel<
                        DeviceType, TransposeParam<DeviceType>,
                        operators::TransposeKernel<DeviceType, T>> {
 public:
  TransposeOp(const std::string &type, const VariableNameMap &inputs,
              const VariableNameMap &outputs,
              const framework::AttributeMap &attrs,
              std::shared_ptr<framework::Scope> scope)
      : framework::OperatorWithKernel<
            DeviceType, TransposeParam<DeviceType>,
            operators::TransposeKernel<DeviceType, T>>(type, inputs, outputs,
                                                       attrs, scope) {}
  void InferShape() const override;
};

}  // namespace operators
}  // namespace paddle_mobile

#endif
