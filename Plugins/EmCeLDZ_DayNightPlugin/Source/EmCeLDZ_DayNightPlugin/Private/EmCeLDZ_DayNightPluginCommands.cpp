// Copyright Epic Games, Inc. All Rights Reserved.

#include "EmCeLDZ_DayNightPluginCommands.h"

#define LOCTEXT_NAMESPACE "FEmCeLDZ_DayNightPluginModule"

void FEmCeLDZ_DayNightPluginCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "EmCeLDZ_DayNightPlugin", "Execute EmCeLDZ_DayNightPlugin action", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
