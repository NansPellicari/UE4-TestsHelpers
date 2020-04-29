#pragma once

#include "CoreMinimal.h"

#include "MockObject.generated.h"

UCLASS()
class NANSUE4TESTSHELPERS_API UMockObject : public UObject
{
	GENERATED_BODY()
public:
	void SetMyWorld(UWorld* World)
	{
		MyWorld = World;
	}

	virtual class UWorld* GetWorld() const override
	{
		return MyWorld;
	}

private:
	UPROPERTY()
	UWorld* MyWorld;
};
