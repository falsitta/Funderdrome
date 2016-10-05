// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFunderDrome.h"
#include "UBpVideoSettingsLib.h"


UGameUserSettings* UUBpVideoSettingsLib::GetGameUserSettings()
{
	if (GEngine != nullptr)
	{
		return GEngine->GameUserSettings;
	}

	return nullptr;
}
bool UUBpVideoSettingsLib::GetSupportedScreenResolutions(TArray<FString>& Resolutions)
{
	FScreenResolutionArray ResolutionsArray;

	if (RHIGetAvailableResolutions(ResolutionsArray, true))  // "RHI" dependency
	{
		for (const FScreenResolutionRHI& Resolution : ResolutionsArray)
		{
			FString StrW = FString::FromInt(Resolution.Width);
			FString StrH = FString::FromInt(Resolution.Height);
			Resolutions.AddUnique(StrW + "x" + StrH);
		}

		return true;
	}

	return false;  // failed to obtain screen resolutions
}
// Set the desired screen resolution (does not change it yet)
bool UUBpVideoSettingsLib::SetScreenResolution(
	const int32 Width, const int32 Height, const bool Fullscreen)
{
	UGameUserSettings* Settings = GetGameUserSettings();
	if (!Settings)
	{
		return false;
	}

	Settings->SetScreenResolution(FIntPoint(Width, Height));
	Settings->SetFullscreenMode(Fullscreen ? EWindowMode::Fullscreen : EWindowMode::Windowed);
	return true;
}
// Change the current screen resolution
bool UUBpVideoSettingsLib::ChangeScreenResolution(
	const int32 Width, const int32 Height, const bool Fullscreen)
{
	UGameUserSettings* Settings = GetGameUserSettings();
	if (!Settings)
	{
		return false;
	}

	EWindowMode::Type WindowMode = Fullscreen ? EWindowMode::Fullscreen : EWindowMode::Windowed;
	Settings->RequestResolutionChange(Width, Height, WindowMode, false);
	return true;
}
// Get the current video quality settings
bool UUBpVideoSettingsLib::GetVideoQualitySettings(
    int32& AntiAliasing, int32& Effects, int32& PostProcess,
    int32& Resolution, int32& Shadow, int32& Texture, int32& ViewDistance)
{
    UGameUserSettings* Settings = GetGameUserSettings();
    if(!Settings)
    {
        return false;
    }
 
    AntiAliasing = Settings->ScalabilityQuality.AntiAliasingQuality;
    Effects = Settings->ScalabilityQuality.EffectsQuality;
    PostProcess = Settings->ScalabilityQuality.PostProcessQuality;
    Resolution = Settings->ScalabilityQuality.ResolutionQuality;
    Shadow = Settings->ScalabilityQuality.ShadowQuality;
    Texture = Settings->ScalabilityQuality.TextureQuality;
    ViewDistance = Settings->ScalabilityQuality.ViewDistanceQuality;
    return true;
}
// Set the quality settings (not applied nor saved yet)
bool UUBpVideoSettingsLib::SetVideoQualitySettings(
	const int32 AntiAliasing, const int32 Effects, const int32 PostProcess,
	const int32 Resolution, const int32 Shadow, const int32 Texture, const int32 ViewDistance)
{
	UGameUserSettings* Settings = GetGameUserSettings();
	if (!Settings)
	{
		return false;
	}

	Settings->ScalabilityQuality.AntiAliasingQuality = AntiAliasing;
	Settings->ScalabilityQuality.EffectsQuality = Effects;
	Settings->ScalabilityQuality.PostProcessQuality = PostProcess;
	Settings->ScalabilityQuality.ResolutionQuality = Resolution;
	Settings->ScalabilityQuality.ShadowQuality = Shadow;
	Settings->ScalabilityQuality.TextureQuality = Texture;
	Settings->ScalabilityQuality.ViewDistanceQuality = ViewDistance;
	return true;
}
// Confirm and save current video mode (resolution and fullscreen/windowed)
bool UUBpVideoSettingsLib::SaveVideoModeAndQuality()
{
	UGameUserSettings* Settings = GetGameUserSettings();
	if (!Settings)
	{
		return false;
	}

	Settings->ConfirmVideoMode();
	Settings->ApplyNonResolutionSettings();
	Settings->SaveSettings();
	return true;
}
 
