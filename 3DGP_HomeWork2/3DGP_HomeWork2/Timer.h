#pragma once
#include "stdafx.h"

const ULONG MAX_SAMPLE_COUNT = 50; // 50ȸ�� ������ ó���ð��� �����Ͽ� ����Ѵ�.

class CGameTimer
{
public:
	CGameTimer();
	virtual ~CGameTimer();

	void Start();
	void Stop();
	void Reset();

	/*
		Tick			: Ÿ�̸��� �ð��� �����Ѵ�.
		GetFrameRate	: ������ ����Ʈ�� ��ȯ�Ѵ�.	
		etTimeElapsed	: �������� ��� ��� �ð��� ��ȯ�Ѵ�.
	*/
	void				Tick(float fLockFPS = 0.0f);									
	unsigned long		GetFrameRate(LPTSTR lpszString = NULL, int nCharacters = 0);	
	float				GetTimeElapsed();												

private:	
	/*
		m_bHardwareHasPerformanceCounter	: ��ǻ�Ͱ� Performance Counter�� ������ �ִ� ��
		m_fTimeScale						: Scale Counter�� ��
		m_fTimeElapsed						: ������ ������ ���� ������ �ð�
		m_nCurrentTime						: ������ �ð�
		m_nLastTime							: ������ �������� �ð�
		m_nPerformanceFrequency				: ��ǻ���� Performance Frequency
			
		m_fFrameTime[MAX_SAMPLE_COUNT]		: ������ �ð��� �����ϱ� ���� �迭
		m_nSampleCount						: ������ ������ Ƚ��
			
		m_nCurrentFrameRate					: ������ ������ ����Ʈ
		m_nFramesPerSecond					: �ʴ� ������ ��
		m_fFPSTimeElapsed					: ������ ����Ʈ ��� �ҿ� �ð� 
	*/
	bool			m_bHardwareHasPerformanceCounter;	
	float			m_fTimeScale;						
	float			m_fTimeElapsed;						
	__int64			m_nCurrentTime;						
	__int64			m_nLastTime;						
	__int64			m_nPerformanceFrequency;			

	float			m_fFrameTime[MAX_SAMPLE_COUNT];		
	ULONG			m_nSampleCount;						

	unsigned long	m_nCurrentFrameRate;				
	unsigned long	m_nFramesPerSecond;					
	float			m_fFPSTimeElapsed;					

	bool			m_bStopped;

};

