#pragma once
#include "stdafx.h"

const ULONG MAX_SAMPLE_COUNT = 50; // 50회의 프레임 처리시간을 누적하여 평균한다.

class CGameTimer
{
public:
	CGameTimer();
	virtual ~CGameTimer();

	void Start();
	void Stop();
	void Reset();

	/*
		Tick			: 타이머의 시간을 갱신한다.
		GetFrameRate	: 프레임 레이트를 반환한다.	
		etTimeElapsed	: 프레임의 평균 경과 시간을 반환한다.
	*/
	void				Tick(float fLockFPS = 0.0f);									
	unsigned long		GetFrameRate(LPTSTR lpszString = NULL, int nCharacters = 0);	
	float				GetTimeElapsed();												

private:	
	/*
		m_bHardwareHasPerformanceCounter	: 컴퓨터가 Performance Counter를 가지고 있는 가
		m_fTimeScale						: Scale Counter의 양
		m_fTimeElapsed						: 마지막 프레임 이후 지나간 시간
		m_nCurrentTime						: 현재의 시간
		m_nLastTime							: 마지막 프레임의 시간
		m_nPerformanceFrequency				: 컴퓨터의 Performance Frequency
			
		m_fFrameTime[MAX_SAMPLE_COUNT]		: 프레임 시간을 누적하기 위한 배열
		m_nSampleCount						: 누적된 프레임 횟수
			
		m_nCurrentFrameRate					: 현재의 프레임 레이트
		m_nFramesPerSecond					: 초당 프레임 수
		m_fFPSTimeElapsed					: 프레임 레이트 계산 소요 시간 
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

