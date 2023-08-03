// Copyright Epic Games, Inc. All Rights Reserved.

#include "EmCeLDZ_DayNightPlugin.h"
#include "EmCeLDZ_DayNightPluginStyle.h"
#include "EmCeLDZ_DayNightPluginCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
#include <Engine/DirectionalLight.h>
#include <Components/LightComponent.h>
#include <Kismet/GameplayStatics.h>
#include <Engine/PostProcessVolume.h>

static const FName EmCeLDZ_DayNightPluginTabName("EmCeLDZ_DayNightPlugin");

#define LOCTEXT_NAMESPACE "FEmCeLDZ_DayNightPluginModule"

void FEmCeLDZ_DayNightPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FEmCeLDZ_DayNightPluginStyle::Initialize();
	FEmCeLDZ_DayNightPluginStyle::ReloadTextures();

	FEmCeLDZ_DayNightPluginCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FEmCeLDZ_DayNightPluginCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FEmCeLDZ_DayNightPluginModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FEmCeLDZ_DayNightPluginModule::RegisterMenus));
}

void FEmCeLDZ_DayNightPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FEmCeLDZ_DayNightPluginStyle::Shutdown();

	FEmCeLDZ_DayNightPluginCommands::Unregister();
}


void FEmCeLDZ_DayNightPluginModule::PluginButtonClicked()

{
	// Find the light in the scene.
	AActor* FoundActor = FindObject(ADirectionalLight::StaticClass());
	//Find post process volume in the scene.
	AActor* FoundPostProcessVolume = FindObject(APostProcessVolume::StaticClass());




	if (FoundActor && FoundPostProcessVolume)
	{
		ADirectionalLight* Light = Cast<ADirectionalLight>(FoundActor);

		APostProcessVolume* PostProcessVolume = Cast<APostProcessVolume>(FoundPostProcessVolume);

		// Check if light and post process volume is founded.

		if (Light && PostProcessVolume)
		{
			ULightComponent* LightComponent = Light->GetLightComponent();

			
		   float LightIntensity = LightComponent->Intensity;

			if (LightComponent->Intensity == 0.1f)

			

			{
				// Directional light settings.
				LightComponent->SetIntensity(5.0);

				// Set sun rotation.
				Light->SetActorRotation(FRotator(-20.0f, 100.0f, 0.0f));

				// Day Post process volume settings.
				PostProcessVolume->Settings.bOverride_AutoExposureMinBrightness = true;
				PostProcessVolume->Settings.AutoExposureMinBrightness = 0.1f;

				// Post process lens flare settings.
				PostProcessVolume->Settings.bOverride_LensFlareIntensity = true;
				PostProcessVolume->Settings.LensFlareIntensity = 1.0f;

				// Print message on screen and console.
				UE_LOG(LogTemp, Warning, TEXT("DAY"));
				FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("Day", "DAY"));




			}

			else 
			{
				// Directional light settings.
				LightComponent->SetIntensity(0.1f);

				// Set sun rotation.
				Light->SetActorRotation(FRotator(100.0f, 0.0f, 0.0f));

				// Night Post process volume settings.
				PostProcessVolume->Settings.bOverride_AutoExposureMinBrightness = true;
				PostProcessVolume->Settings.AutoExposureMinBrightness = 0.0f;

				// Post process lens flare settings.
				PostProcessVolume->Settings.bOverride_LensFlareIntensity = false;
				PostProcessVolume->Settings.LensFlareIntensity = 0.0f;

				// Print message on screen and console.
				UE_LOG(LogTemp, Warning, TEXT("NIGHT"));
				FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("Night", "NIGHT"));




			}
		}

		// If light or post process volume is not founded print message on screen and console.

		else
		{

			// Console message.
			UE_LOG(LogTemp, Warning, TEXT("LIGHT OR POSTPROCESS COMPONENT IS NOT FOUNDED"));

			// On screen message in editor.
			FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("LightOrPostProcessComponentNotFounded", "LIGHT OR POSTPROCESS COMPONENT IS NOT FOUNDED"));


		}
	}

	// If light or post process volume is not founded print message on screen and console.

	else
	{

		// Console message.
		UE_LOG(LogTemp, Warning, TEXT("LIGHT OR POSTPROCESS COMPONENT IS NOT FOUNDED"));

		// On screen message in editor.
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("LightOrPostProcessComponentNotFounded", "LIGHT OR POSTPROCESS COMPONENT IS NOT FOUNDED"));


	}


}

void FEmCeLDZ_DayNightPluginModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FEmCeLDZ_DayNightPluginCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FEmCeLDZ_DayNightPluginCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

AActor* FEmCeLDZ_DayNightPluginModule::FindObject(TSubclassOf<AActor> ActorClass)
{

	TArray<AActor*> FoundActors;
	UWorld* World = GEditor->GetEditorWorldContext().World();

	if (World)
	{
		UGameplayStatics::GetAllActorsOfClass(World, ActorClass, FoundActors);

		if (FoundActors.Num() > 0)
		{
			return FoundActors[0];
		}


	}



	return nullptr;

}




#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FEmCeLDZ_DayNightPluginModule, EmCeLDZ_DayNightPlugin)