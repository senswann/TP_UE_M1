// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TP_UE : ModuleRules
{
	public TP_UE(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
