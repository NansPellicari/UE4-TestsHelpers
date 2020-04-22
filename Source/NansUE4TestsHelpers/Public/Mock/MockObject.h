#pragma once

#include "CoreMinimal.h"

#include "MockObject.generated.h"

UCLASS()
class UMockObject : public UObject
{
	GENERATED_BODY()
public:
	void SetMyWorld(TSharedPtr<UWorld> World)
	{
		MyWorld = World;
	}

	virtual class UWorld* GetWorld() const override
	{
		return MyWorld.Get();
	}

private:
	TSharedPtr<UWorld> MyWorld;
};
