#pragma once

#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "Engine/EngineBaseTypes.h"
#include "Engine/EngineTypes.h"
#include "EngineGlobals.h"

namespace NTestWorld
{
	UWorld* CreateAndPlay(EWorldType::Type Type)
	{
		const double StartTime = FPlatformTime::Seconds();
		UWorld* World = UWorld::CreateWorld(Type, false);
		FWorldContext& WorldContext = GEngine->CreateNewWorldContext(Type);
		WorldContext.SetCurrentWorld(World);

		FURL URL;
		World->InitializeActorsForPlay(URL);
		World->BeginPlay();

		return World;
	}

	void Destroy(UWorld* World)
	{
		GEngine->DestroyWorldContext(World);
		World->DestroyWorld(false);
	}

	// https://github.com/EpicGames/UnrealEngine/blob/release/Engine/Source/Runtime/Engine/Private/TimerManagerTests.cpp
	void Tick(UWorld* World, float Time = 1.f)
	{
		const float Step = 0.1f;
		while (Time > 0.f)
		{
			World->Tick(ELevelTick::LEVELTICK_All, FMath::Min(Time, Step));
			Time -= Step;

			GFrameCounter++;
		}
	}

	struct FDummyDelegate
	{
		FDummyDelegate()
		{
			Count = 0;
		}

		void Callback()
		{
			++Count;
		}
		void Reset()
		{
			Count = 0;
		}

		uint8 Count;
	};
}	 // namespace NTestWorld