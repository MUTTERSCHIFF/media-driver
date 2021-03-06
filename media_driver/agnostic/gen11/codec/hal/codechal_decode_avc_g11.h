/*
* Copyright (c) 2017, Intel Corporation
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
* OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*/
//!
//! \file      codechal_decode_avc_g11.h 
//! \brief     This modules implements Render interface layer for AVC decoding to be used on all operating systems/DDIs, across CODECHAL components. 
//!
//!
//! \file     codechal_decode_avc_g11.h
//! \brief    Defines the decode interface extension for AVC.
//! \details  Defines all types, macros, and functions required by CodecHal for AVC decoding. 
//!           Definitions are not externally facing.
//!

#ifndef __CODECHAL_DECODER_AVC_G11_H__
#define __CODECHAL_DECODER_AVC_G11_H__

#include "codechal_decode_avc.h"
#include "codechal_decode_singlepipe_virtualengine.h"

//!
//! \class CodechalDecodeAvcG11 
//! \brief This class defines the member fields, functions etc used by AVC decoder.
//!
class CodechalDecodeAvcG11 : public CodechalDecodeAvc
{
public:
    //!
    //! \brief  Constructor
    //! \param    [in] hwInterface
    //!           Hardware interface
    //! \param    [in] debugInterface
    //!           Debug interface
    //! \param    [in] standardInfo
    //!           The information of decode standard for this instance
    //!
    CodechalDecodeAvcG11(
        CodechalHwInterface *hwInterface,
        CodechalDebugInterface* debugInterface,
        PCODECHAL_STANDARD_INFO standardInfo);

    //!
    //! \brief    Copy constructor
    //!
    CodechalDecodeAvcG11(const CodechalDecodeAvcG11&) = delete;

    //!
    //! \brief    Copy assignment operator
    //!
    CodechalDecodeAvcG11& operator=(const CodechalDecodeAvcG11&) = delete;

    //!
    //! \brief    Destructor
    //!
    ~CodechalDecodeAvcG11();

    //!
    //! \brief    Allocate and initialize AVC decoder standard
    //! \param    [in] settings
    //!           Pointer to CodechalSetting
    //! \return   MOS_STATUS
    //!           MOS_STATUS_SUCCESS if success, else fail reason
    //!
    MOS_STATUS  AllocateStandard(
        CodechalSetting *          settings) override;

    //!
    //! \brief  Set states for each frame to prepare for GEN11 AVC decode
    //! \return MOS_STATUS
    //!         MOS_STATUS_SUCCESS if success, else fail reason
    //!
    MOS_STATUS  SetFrameStates() override;

    //!
    //! \brief    AVC decoder state level function
    //! \details  State level function for GEN11 AVC decoder
    //!
    //! \return   MOS_STATUS
    //!           MOS_STATUS_SUCCESS if success, else fail reason
    //!
    MOS_STATUS  DecodeStateLevel() override;

    //!
    //! \brief    AVC decoder primitive level function
    //! \details  Primitive level function for GEN specific AVC decoder
    //!
    //! \return   MOS_STATUS
    //!           MOS_STATUS_SUCCESS if success, else fail reason
    //!
    MOS_STATUS  DecodePrimitiveLevel() override;

protected:

    //!
    //! \brief  Set up params for gpu context creation
    //! \return   MOS_STATUS
    //!           MOS_STATUS_SUCCESS if success, else fail reason
    //!
    MOS_STATUS SetGpuCtxCreatOption(CodechalSetting * settings) override;
    
    PCODECHAL_DECODE_SINGLEPIPE_VIRTUALENGINE_STATE m_veState;  //!< single pipe virtual engine state
};

#endif  // __CODECHAL_DECODER_AVC_G11_H__

