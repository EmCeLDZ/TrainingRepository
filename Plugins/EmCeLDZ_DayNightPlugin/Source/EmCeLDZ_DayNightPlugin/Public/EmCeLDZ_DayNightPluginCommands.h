// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "EmCeLDZ_DayNightPluginStyle.h"

class FEmCeLDZ_DayNightPluginCommands : public TCommands<FEmCeLDZ_DayNightPluginCommands>
{
public:

	FEmCeLDZ_DayNightPluginCommands()
		: TCommands<FEmCeLDZ_DayNightPluginCommands>(TEXT("EmCeLDZ_DayNightPlugin"), NSLOCTEXT("Contexts", "EmCeLDZ_DayNightPlugin", "EmCeLDZ_DayNightPlugin Plugin"), NAME_None, FEmCeLDZ_DayNightPluginStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
