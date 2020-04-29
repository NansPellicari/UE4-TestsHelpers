#pragma once

#include "Runtime/Engine/Classes/Engine/GameInstance.h"

#include "MockGameInstance.generated.h"

UCLASS()
class NANSUE4TESTSHELPERS_API UMockGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	void SetWorldContext(struct FWorldContext* _WorldContext)
	{
		WorldContext = _WorldContext;
	}
};