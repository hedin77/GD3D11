// Copyright (c) 2011 NVIDIA Corporation. All rights reserved.
//
// TO  THE MAXIMUM  EXTENT PERMITTED  BY APPLICABLE  LAW, THIS SOFTWARE  IS PROVIDED
// *AS IS*  AND NVIDIA AND  ITS SUPPLIERS DISCLAIM  ALL WARRANTIES,  EITHER  EXPRESS
// OR IMPLIED, INCLUDING, BUT NOT LIMITED  TO, NONINFRINGEMENT,IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  IN NO EVENT SHALL  NVIDIA 
// OR ITS SUPPLIERS BE  LIABLE  FOR  ANY  DIRECT, SPECIAL,  INCIDENTAL,  INDIRECT,  OR  
// CONSEQUENTIAL DAMAGES WHATSOEVER (INCLUDING, WITHOUT LIMITATION,  DAMAGES FOR LOSS 
// OF BUSINESS PROFITS, BUSINESS INTERRUPTION, LOSS OF BUSINESS INFORMATION, OR ANY 
// OTHER PECUNIARY LOSS) ARISING OUT OF THE  USE OF OR INABILITY  TO USE THIS SOFTWARE, 
// EVEN IF NVIDIA HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
//
// Please direct any bugs or questions to SDKFeedback@nvidia.com

#ifndef _OCEAN_WAVE_H
#define _OCEAN_WAVE_H

#include <d3d11_1.h>

#include "CSFFT/fft_512x512.h"

//#define CS_DEBUG_BUFFER
#define PAD16(n) (((n)+15)/16*16)

struct OceanParameter
{
	// Must be power of 2.
	int dmap_dim;
	// Typical value is 1000 ~ 2000
	float patch_length;

	// Adjust the time interval for simulation.
	float time_scale;
	// Amplitude for transverse wave. Around 1.0
	float wave_amplitude;
	// Wind direction. Normalization not required.
	XMFLOAT2 wind_dir;
	// Around 100 ~ 1000
	float wind_speed;
	// This value damps out the waves against the wind direction.
	// Smaller value means higher wind dependency.
	float wind_dependency;
	// The amplitude for longitudinal wave. Must be positive.
	float choppy_scale;
};


class OceanSimulator
{
public:
	OceanSimulator(OceanParameter& params, Microsoft::WRL::ComPtr<ID3D11Device1> pd3dDevice);
	~OceanSimulator();

	// -------------------------- Initialization & simulation routines ------------------------

	// Update ocean wave when tick arrives.
	void updateDisplacementMap(float time);

	// Texture access
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> getD3D11DisplacementMap();
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> getD3D11GradientMap();

	const OceanParameter& getParameters();


protected:
	OceanParameter m_param;

	// ---------------------------------- GPU shading asset -----------------------------------

	// D3D objects
	Microsoft::WRL::ComPtr<ID3D11Device1> m_pd3dDevice;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_pd3dImmediateContext;
	
	// Displacement map
	Microsoft::WRL::ComPtr<ID3D11Texture2D> m_pDisplacementMap;		// (RGBA32F)
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_pDisplacementSRV;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_pDisplacementRTV;

	// Gradient field
	Microsoft::WRL::ComPtr<ID3D11Texture2D> m_pGradientMap;			// (RGBA16F)
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_pGradientSRV;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_pGradientRTV;

	// Samplers
	Microsoft::WRL::ComPtr<ID3D11SamplerState> m_pPointSamplerState;

	// Initialize the vector field.
	void initHeightMap(OceanParameter& params, XMFLOAT2 * out_h0, float * out_omega);


	// ----------------------------------- CS simulation data ---------------------------------

	// Initial height field H(0) generated by Phillips spectrum & Gauss distribution.
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_pBuffer_Float2_H0;
	Microsoft::WRL::ComPtr<ID3D11UnorderedAccessView> m_pUAV_H0;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_pSRV_H0;

	// Angular frequency
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_pBuffer_Float_Omega;
	Microsoft::WRL::ComPtr<ID3D11UnorderedAccessView> m_pUAV_Omega;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_pSRV_Omega;

	// Height field H(t), choppy field Dx(t) and Dy(t) in frequency domain, updated each frame.
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_pBuffer_Float2_Ht;
	Microsoft::WRL::ComPtr<ID3D11UnorderedAccessView> m_pUAV_Ht;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_pSRV_Ht;

	// Height & choppy buffer in the space domain, corresponding to H(t), Dx(t) and Dy(t)
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_pBuffer_Float_Dxyz;
	Microsoft::WRL::ComPtr<ID3D11UnorderedAccessView> m_pUAV_Dxyz;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_pSRV_Dxyz;

	Microsoft::WRL::ComPtr<ID3D11Buffer> m_pQuadVB;

	// Shaders, layouts and constants
	Microsoft::WRL::ComPtr<ID3D11ComputeShader> m_pUpdateSpectrumCS;

	Microsoft::WRL::ComPtr<ID3D11VertexShader> m_pQuadVS;
	Microsoft::WRL::ComPtr<ID3D11PixelShader> m_pUpdateDisplacementPS;
	Microsoft::WRL::ComPtr<ID3D11PixelShader> m_pGenGradientFoldingPS;

	Microsoft::WRL::ComPtr<ID3D11InputLayout> m_pQuadLayout;

	Microsoft::WRL::ComPtr<ID3D11Buffer> m_pImmutableCB;
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_pPerFrameCB;

	// FFT wrap-up
	CSFFT512x512_Plan m_fft_plan;

#ifdef CS_DEBUG_BUFFER
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_pDebugBuffer;
#endif
};

#endif	// _OCEAN_WAVE_H
