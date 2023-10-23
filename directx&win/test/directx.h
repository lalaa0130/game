#pragma once

#include<d3d11.h>
#include<D3DX11.h>

class C_DIRETCX
{
private:
	D3D_DRIVER_TYPE         m_driverType;
	D3D_FEATURE_LEVEL       m_featureLevel;
	ID3D11Device*			m_pd3dDevice;
	ID3D11DeviceContext*	m_pImmediateContext;
	IDXGISwapChain*			m_pSwapChain;
	ID3D11RenderTargetView* m_pRenderTargetView;


public:
	C_DIRETCX();
	HRESULT		InitDevice(HWND hWnd);
	void		CleanupDevice();
	void		Render();
};