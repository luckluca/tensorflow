/* Copyright 2015 Google Inc. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_KERNELS_TRANSPOSE_OP_H_
#define TENSORFLOW_KERNELS_TRANSPOSE_OP_H_

#include "third_party/eigen3/unsupported/Eigen/CXX11/Tensor"
#include "tensorflow/core/framework/op_kernel.h"
#include "tensorflow/core/framework/tensor_types.h"

namespace tensorflow {

template <typename Device, typename T>
class TransposeOp : public OpKernel {
 public:
  explicit TransposeOp(OpKernelConstruction* context);
  void Compute(OpKernelContext* context) override;
};

// Exposed for use in reduction ops
template <typename Device, typename T>
void TransposeTensor(const Device& device, const Tensor& input,
                     const gtl::ArraySlice<int64> input_shape,
                     gtl::ArraySlice<int32> permutation, Tensor* output);

}  // namespace tensorflow

#endif  // TENSORFLOW_KERNELS_TRANSPOSE_OP_H_
