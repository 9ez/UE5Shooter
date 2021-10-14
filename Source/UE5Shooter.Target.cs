// THEY. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class UE5ShooterTarget : TargetRules
{
	public UE5ShooterTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange(new string[] { "UE5Shooter" });
	}
}