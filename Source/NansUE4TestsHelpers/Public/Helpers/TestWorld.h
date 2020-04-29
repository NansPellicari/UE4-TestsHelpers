#pragma once

#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "Engine/EngineBaseTypes.h"
#include "Engine/EngineTypes.h"
#include "EngineGlobals.h"
#include "NansUE4TestsHelpers/Public/Mock/MockGameInstance.h"
#include "NansUE4TestsHelpers/Public/Mock/MockObject.h"
#include "Runtime/Engine/Classes/Engine/Level.h"
#include "Runtime/Engine/Classes/Engine/LocalPlayer.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"

namespace NTestWorld
{
	UWorld* CreateAndPlay(EWorldType::Type Type, bool bWithGameInstance = false)
	{
		UWorld* World = UWorld::CreateWorld(Type, false, FName("MyTestWorld"));
		FWorldContext& WorldContext = GEngine->CreateNewWorldContext(Type);

		WorldContext.SetCurrentWorld(World);

		FURL URL;

		if (bWithGameInstance)
		{
			APlayerController* PC = NewObject<APlayerController>(World->PersistentLevel);
			ULocalPlayer* Player = NewObject<ULocalPlayer>(GEngine);
			PC->SetPlayer(Player);
			Player->SetControllerId(PC->GetUniqueID());
			UMockGameInstance* GI = NewObject<UMockGameInstance>(GEngine);
			WorldContext.OwningGameInstance = GI;
			World->SetGameInstance(GI);
			GI->SetWorldContext(&WorldContext);
			GI->AddLocalPlayer(Player, PC->GetUniqueID());
			World->SetGameMode(URL);
			PC->InitPlayerState();
			World->AddController(PC);
		}

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