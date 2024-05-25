#pragma once
#include "Timer.h"
#include "Shader.h"
#include "Camera.h"

class CScene
{
public:
	CScene();
	~CScene();

	// 씬에서 마우스와 키보드 메시지를 처리한다.
	bool OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM
		lParam);
	bool OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM
		lParam);

	void BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	void ReleaseObjects();

	bool ProcessInput( UCHAR* pKeysBuffer );
	void AnimateObjects(float fTimeElapsed);
	void Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera);

	void ReleaseUploadBuffers();

	// 그래픽 루트 시그니처를 생성한다.
	ID3D12RootSignature* CreateGraphicsRootSignature( ID3D12Device* pd3dDevice );
	ID3D12RootSignature* GetGraphicsRootSignature();

protected:
	//// 씬은 셰이더들의 집합이다. 셰이더들은 게임 객체들의 집합이다.
	//CGameObject** m_ppObjects = NULL;
	//int m_nObjects = 0;

	// 배치(Batch) 처리를 하기 위하여 씬을 셰이더들의 리스트로 표현한다.
	CObjectsShader* m_pShaders = NULL;
	int m_nShaders = 0;

protected:
	ID3D12RootSignature* m_pd3dGraphicsRootSignature = NULL;
};

