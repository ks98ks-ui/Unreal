// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class First : ModuleRules
{
	public First(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"First",
			"First/Variant_Platforming",
			"First/Variant_Platforming/Animation",
			"First/Variant_Combat",
			"First/Variant_Combat/AI",
			"First/Variant_Combat/Animation",
			"First/Variant_Combat/Gameplay",
			"First/Variant_Combat/Interfaces",
			"First/Variant_Combat/UI",
			"First/Variant_SideScrolling",
			"First/Variant_SideScrolling/AI",
			"First/Variant_SideScrolling/Gameplay",
			"First/Variant_SideScrolling/Interfaces",
			"First/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
