// THEY. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class UE5ShooterEditorTarget : TargetRules
{
	public UE5ShooterEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "UE5Shooter" } );
	}
}
