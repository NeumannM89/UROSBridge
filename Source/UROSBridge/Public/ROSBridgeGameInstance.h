// Copyright 2017-2019, Institute for Artificial Intelligence - University of Bremen
#pragma once

#include "UROSBridge.h"
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Tickable.h"
#include "ROSBridgeHandler.h"

#include "ROSBridgeGameInstance.generated.h"

/**
 * Base class for an example GameInstance that holds an instance of FROSBridgeHandler.
 * The class is tickable and will call FROSBridgeHandler::Process() on every Tick.
 * To use this class, create a derived blueprint from it, configure
 * ROSBridgeServerHost and ROSBridgeServerPort if necessary and set
 * this Blueprint as the Game Instance for your project. This can be done
 * in the UE4Editor -> Project Settings -> Maps & Modes.
 */
UCLASS()
class UROSBRIDGE_API UROSBridgeGameInstance : public UGameInstance, public FTickableGameObject
{
	GENERATED_BODY()

protected:
	// Default constructor
	UROSBridgeGameInstance();

	/* UGameInstance interface */
	// Called when the game instance is started either normally or through PIE
	virtual void OnStart() override;
	// Cleanup opportunity when shutting down
	virtual void Shutdown() override;

	/* FTickableGameObject interface */
	virtual void Tick(float DeltaTime) override;
	virtual bool IsTickable() const override;
	virtual TStatId GetStatId() const override;

public:
	TSharedPtr<FROSBridgeHandler> ROSHandler;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ROS")
	FString ROSBridgeServerHost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ROS")
	int32 ROSBridgeServerPort;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ROS")
	bool bConnectToROS;
};
