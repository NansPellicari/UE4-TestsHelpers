// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
	public class NansUE4TestsHelpers : ModuleRules
	{
		public NansUE4TestsHelpers(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
				}
				);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"CoreUObject",
				}
				);
		}
	}
}
