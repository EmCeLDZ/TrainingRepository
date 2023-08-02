

using UnrealBuildTool;
using System.Collections.Generic;

public class GitTrainingProjectEditorTarget : TargetRules
{
	public GitTrainingProjectEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "GitTrainingProject" } );
	}
}
