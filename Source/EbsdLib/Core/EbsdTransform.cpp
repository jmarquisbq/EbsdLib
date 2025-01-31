/* ============================================================================
 * Copyright (c) 2009-2016 BlueQuartz Software, LLC
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice, this
 * list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.
 *
 * Neither the name of BlueQuartz Software, the US Air Force, nor the names of its
 * contributors may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The code contained herein was partially funded by the following contracts:
 *    United States Air Force Prime Contract FA8650-07-D-5800
 *    United States Air Force Prime Contract FA8650-10-D-5210
 *    United States Prime Contract Navy N00173-07-C-2068
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "EbsdTransform.h"

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
EbsdTransform::EbsdTransform()

    = default;

EbsdLib::EbsdToSampleCoordinateMapping EbsdTransform::IdentifyStandardTransformation(const std::array<float, 4>& sampleTransformation, const std::array<float, 4>& eulerTransformation)
{

  // TSL/EDAX
  if(sampleTransformation[0] == 180.0f && sampleTransformation[1] == 0.0f && sampleTransformation[2] == 1.0f && sampleTransformation[3] == 0.0f

     && eulerTransformation[0] == 90.0f && eulerTransformation[1] == 0.0f && eulerTransformation[2] == 0.0f && eulerTransformation[3] == 1.0f)

  {
    return EbsdLib::TSLdefault;
  }

  if(sampleTransformation[0] == 180.0f // HKL
     && sampleTransformation[1] == 0.0f && sampleTransformation[2] == 1.0f && sampleTransformation[3] == 0.0f

     && eulerTransformation[0] == 0.0f && eulerTransformation[1] == 0.0f && eulerTransformation[2] == 0.0f && eulerTransformation[3] == 1.0f)

  {
    return EbsdLib::HKLdefault;
  }

  if(sampleTransformation[0] == 0.0f // HEDM
     && sampleTransformation[1] == 0.0f && sampleTransformation[2] == 0.0f && sampleTransformation[3] == 1.0f

     && eulerTransformation[0] == 0.0f && eulerTransformation[1] == 0.0f && eulerTransformation[2] == 0.0f && eulerTransformation[3] == 1.0f)

  {
    return EbsdLib::HEDMdefault;
  }

  return EbsdLib::UnknownCoordinateMapping;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
EbsdTransform::~EbsdTransform() = default;

// -----------------------------------------------------------------------------
std::string EbsdTransform::getNameOfClass() const
{
  return std::string("EbsdTransform");
}

// -----------------------------------------------------------------------------
std::string EbsdTransform::ClassName()
{
  return std::string("EbsdTransform");
}
