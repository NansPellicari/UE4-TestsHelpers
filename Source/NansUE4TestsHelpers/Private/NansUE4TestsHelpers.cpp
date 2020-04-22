// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "INansUE4TestsHelpers.h"


class FNansUE4TestsHelpers : public INansUE4TestsHelpers
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FNansUE4TestsHelpers, NansUE4TestsHelpers )



void FNansUE4TestsHelpers::StartupModule()
{
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
}


void FNansUE4TestsHelpers::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}



