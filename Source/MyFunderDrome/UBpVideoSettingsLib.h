#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "UBpVideoSettingsLib.generated.h"

#define MIN_SCREEN_WIDTH 1024
#define MIN_SCREEN_HEIGHT 768


/**
* Custom Blueprint Function Library.
*/
UCLASS()
class /* ADD YOUR GAME API NAME HERE !! */ UBpVideoSettingsLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// Get a list of screen resolutions supported on this machine
	UFUNCTION(BlueprintPure, Category = "Video Settings")
		static bool GetSupportedScreenResolutions(TArray<FString>& Resolutions);

	// Get currently set screen resolution
	UFUNCTION(BlueprintPure, Category = "Video Settings")
		static FString GetScreenResolution();

	// Check whether or not we are currently running in fullscreen mode
	UFUNCTION(BlueprintPure, Category = "Video Settings")
		static bool IsInFullscreen();

	// Set the desired screen resolution (does not change it yet)
	UFUNCTION(BlueprintCallable, Category = "Video Settings")
		static bool SetScreenResolution(const int32 Width, const int32 Height, const bool Fullscreen);

	// Change the current screen resolution
	UFUNCTION(BlueprintCallable, Category = "Video Settings")
		static bool ChangeScreenResolution(const int32 Width, const int32 Height, const bool Fullscreen);

	// Get the current video quality settings
	UFUNCTION(BlueprintCallable, Category = "Video Settings")
		static bool GetVideoQualitySettings(int32& AntiAliasing, int32& Effects, int32& PostProcess, int32& Resolution, int32& Shadow, int32& Texture, int32& ViewDistance);

	// Set the quality settings (not applied nor saved yet)
	UFUNCTION(BlueprintCallable, Category = "Video Settings")
		static bool SetVideoQualitySettings(const int32 AntiAliasing = 3, const int32 Effects = 3, const int32 PostProcess = 3,
			const int32 Resolution = 100, const int32 Shadow = 3, const int32 Texture = 3, const int32 ViewDistance = 3);

	// Check whether or not we have vertical sync enabled
	UFUNCTION(BlueprintPure, Category = "Video Settings")
		static bool IsVSyncEnabled();

	// Set the vertical sync flag
	UFUNCTION(BlueprintCallable, Category = "Video Settings")
		static bool SetVSyncEnabled(const bool VSync);

	// Confirm and save current video mode (resolution and fullscreen/windowed) as well as quality settings
	UFUNCTION(BlueprintCallable, Category = "Video Settings")
		static bool SaveVideoModeAndQuality();

	// Revert to original video settings
	UFUNCTION(BlueprintCallable, Category = "Video Settings")
		static bool RevertVideoMode();

private:
	// Try to get the GameUserSettings object from the engine
	static UGameUserSettings* GetGameUserSettings();
};

// Fill out your copyright notice in the Description page of Project Settings.

/*#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "UBpVideoSettingsLib.generated.h"

UCLASS()
class MYFUNDERDROME_API UUBpVideoSettingsLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

private:
	// Try to get the GameUserSettings object from the engine
	static UGameUserSettings* GetGameUserSettings();
	// Get a list of screen resolutions supported on this machine
	UFUNCTION(BlueprintPure, Category = "Video Settings")
		static bool GetSupportedScreenResolutions(TArray<FString>& Resolutions);
	UFUNCTION(BlueprintPure, Category = "Video Settings")
	    static bool SetScreenResolution(const int32 Width, const int32 Height, const bool Fullscreen);
	UFUNCTION(BlueprintPure, Category = "Video Settings")
		static bool ChangeScreenResolution(const int32 Width, const int32 Height, const bool Fullscreen);
	UFUNCTION(BlueprintPure, Category = "Video Settings")
		static bool GetVideoQualitySettings(int32& AntiAliasing, int32& Effects, int32& PostProcess,
			int32& Resolution, int32& Shadow, int32& Texture, int32& ViewDistance);
	UFUNCTION(BlueprintPure, Category = "Video Settings")
		static bool SetVideoQualitySettings (const int32 AntiAliasing, const int32 Effects, const int32 PostProcess,
			const int32 Resolution, const int32 Shadow, const int32 Texture, const int32 ViewDistance);
	UFUNCTION(BlueprintPure, Category = "Video Settings")
		static bool SaveVideoModeAndQuality();
};*/
