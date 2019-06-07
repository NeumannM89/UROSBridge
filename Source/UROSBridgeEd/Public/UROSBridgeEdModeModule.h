// Copyright 2017-2019, Institute for Artificial Intelligence - University of Bremen

#pragma once

#include "CoreMinimal.h"
#include "ModuleManager.h"
#include "Styling/ISlateStyle.h"
#include "Styling/SlateStyle.h"

class FUROSBridgeEdModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	void StartupModule() override;
	void ShutdownModule() override;

	static void Initialize();

	static TSharedPtr<class ISlateStyle> Get();

	static FName GetStyleSetName();
private:
	static FString InContent(const FString& RelativePath, const ANSICHAR* Extension);

private:
	static TSharedPtr<class FSlateStyleSet> StyleSet;
};
