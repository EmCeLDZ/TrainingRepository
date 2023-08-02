

using UnrealBuildTool;
using System.Collections.Generic;

public class GitTrainingProjectTarget : TargetRules
{
	public GitTrainingProjectTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "GitTrainingProject" } );
	}
}
