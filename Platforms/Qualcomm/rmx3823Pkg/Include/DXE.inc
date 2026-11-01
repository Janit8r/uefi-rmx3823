  INF MdeModulePkg/Core/Dxe/DxeMain.inf
  INF MdeModulePkg/Universal/PCD/Dxe/Pcd.inf

!if $(RMX3823_VENDOR_HW) == 1
  INF Binaries/qrd8550/QcomPkg/Drivers/EnvDxe/EnvDxe.inf
!endif

  INF MdeModulePkg/Universal/ReportStatusCodeRouter/RuntimeDxe/ReportStatusCodeRouterRuntimeDxe.inf
  INF MdeModulePkg/Universal/StatusCodeHandler/RuntimeDxe/StatusCodeHandlerRuntimeDxe.inf
  INF ArmPkg/Drivers/CpuDxe/CpuDxe.inf
  INF MdeModulePkg/Core/RuntimeDxe/RuntimeDxe.inf
  INF MdeModulePkg/Universal/SecurityStubDxe/SecurityStubDxe.inf

!if $(RMX3823_VENDOR_HW) == 1
  INF Binaries/qrd8550/QcomPkg/Drivers/ShmBridgeDxe/ShmBridgeDxeLA.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/TzDxe/ScmDxeCompat.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/TzDxe/TzDxeLA.inf
!endif

  INF MdeModulePkg/Universal/WatchdogTimerDxe/WatchdogTimer.inf
  INF MdeModulePkg/Universal/CapsuleRuntimeDxe/CapsuleRuntimeDxe.inf
  INF MdeModulePkg/Universal/Variable/RuntimeDxe/VariableRuntimeDxe.inf
  INF EmbeddedPkg/EmbeddedMonotonicCounter/EmbeddedMonotonicCounter.inf
  INF MdeModulePkg/Universal/ResetSystemRuntimeDxe/ResetSystemRuntimeDxe.inf
  INF EmbeddedPkg/RealTimeClockRuntimeDxe/RealTimeClockRuntimeDxe.inf
  INF EmbeddedPkg/MetronomeDxe/MetronomeDxe.inf
  INF MdeModulePkg/Universal/HiiDatabaseDxe/HiiDatabaseDxe.inf
  INF ArmPkg/Drivers/ArmGicDxe/ArmGicDxe.inf
  INF ArmPkg/Drivers/TimerDxe/TimerDxe.inf

!if $(RMX3823_VENDOR_HW) == 1
  INF Binaries/qrd8550/QcomPkg/Drivers/ChipInfoDxe/ChipInfoDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/IPCCDxe/IPCCDxe.inf
  #INF Binaries/qrd8550/QcomPkg/Drivers/GLinkDxe/GLinkDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/PlatformInfoDxe/PlatformInfoDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/DALSYSDxe/DALSYSDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/HALIOMMUDxe/HALIOMMUDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/HWIODxe/HWIODxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/I2CDxe/I2CDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/TLMMDxe/TLMMDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/PmicDxe/PmicDxeLa.inf
!endif

  #
  # UniXNU integration.
  #
  # UniXNURamDiskDxe publishes the initrd range that the Android bootloader
  # wrote into /chosen/linux,initrd-start|end as Block I/O. DiskIoDxe,
  # PartitionDxe and Fat then expose the payload's FAT volume, which is how
  # UniXNU reads \EFI\UniXNU\unixnu.toml. All four are mandatory, and they must
  # live in the firmware volume: the payload cannot be discovered otherwise.
  #
  # DarwinBoot is a driver in the firmware volume, not something loaded from a
  # volume - the image verification of this build refuses that.
  #
  # EnglishDxe supplies the Unicode collation service EnhancedFatDxe depends on.
  #
  INF MdeModulePkg/Universal/DevicePathDxe/DevicePathDxe.inf
  INF UniXNUPkg/Driver/UniXNURamDiskDxe/UniXNURamDiskDxe.inf
  INF DarwinBootPkg/Driver/DarwinBoot.inf
  INF MdeModulePkg/Universal/Disk/DiskIoDxe/DiskIoDxe.inf
  INF MdeModulePkg/Universal/Disk/PartitionDxe/PartitionDxe.inf
  INF FatPkg/EnhancedFatDxe/Fat.inf
  INF MdeModulePkg/Universal/Disk/UnicodeCollation/EnglishDxe/EnglishDxe.inf

!if $(RMX3823_VENDOR_HW) == 1
  INF Binaries/qrd8550/QcomPkg/Drivers/UFSDxe/UFSDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/CmdDbDxe/CmdDbDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/PwrUtilsDxe/PwrUtilsDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/RpmhDxe/RpmhDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/NpaDxe/NpaDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/ULogDxe/ULogDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/VcsDxe/VcsDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/ClockDxe/ClockDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/SPMIDxe/SPMIDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/ICBDxe/ICBDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/SmemDxe/SmemDxe.inf
!endif
  INF MdeModulePkg/Universal/BdsDxe/BdsDxe.inf

!if $(RMX3823_VENDOR_HW) == 1
  INF Binaries/qrd8550/QcomPkg/Drivers/RscDxe/RscDxe.inf
!endif

  INF EmbeddedPkg/SimpleTextInOutSerial/SimpleTextInOutSerial.inf
  INF MdeModulePkg/Universal/PrintDxe/PrintDxe.inf
  INF MdeModulePkg/Universal/Console/ConPlatformDxe/ConPlatformDxe.inf
  INF MdeModulePkg/Universal/Console/ConSplitterDxe/ConSplitterDxe.inf
  INF MdeModulePkg/Universal/Console/GraphicsConsoleDxe/GraphicsConsoleDxe.inf

!if $(RMX3823_VENDOR_HW) == 1
  INF Binaries/qrd8550/QcomPkg/Drivers/CPRDxe/CPRDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/GpiDxe/GpiDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/SPIDxe/SPIDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/SdccDxe/SdccDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/FeatureEnablerDxe/FeatureEnablerDxe.inf
!endif

  #
  # Display.
  #
  # USE_CUSTOM_DISPLAY_DRIVER = 0 (the default here) keeps SimpleFbDxe, which
  # publishes a GOP over the framebuffer ABL is already scanning out. That is
  # the only option available today: rmx3823 has no panel XML and no vendor
  # DisplayDxe data in RAW.inc, and on sheng the equivalent vendor chain
  # blanked the panel even with its panel data present.
  #
  # Turning this on before RAW.inc carries the RMX3823 panel data and the
  # DisplayDxe DEPEX glue exists will give a black screen, not a picture.
  #
!if $(USE_CUSTOM_DISPLAY_DRIVER) == 1
  INF Binaries/qrd8550/QcomPkg/Drivers/DisplayDxe/DisplayDxe.inf
!else
  INF SiliciumPkg/Drivers/SimpleFbDxe/SimpleFbDxe.inf
!endif

!if $(RMX3823_VENDOR_HW) == 1
  INF Binaries/qrd8550/QcomPkg/Drivers/ButtonsDxe/ButtonsDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/ChargerExDxe/ChargerExDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/PmicGlinkDxe/PmicGlinkDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/QcomChargerDxe/QcomChargerDxeLA.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/UsbPwrCtrlDxe/UsbPwrCtrlDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/TsensDxe/TsensDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/LimitsDxe/LimitsDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/DDRInfoDxe/DDRInfoDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/UsbfnDwc3Dxe/UsbfnDwc3Dxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/XhciPciEmulationDxe/XhciPciEmulationDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/XhciDxe/XhciDxe.inf
!endif

  INF MdeModulePkg/Bus/Usb/UsbBusDxe/UsbBusDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbKbDxe/UsbKbDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe.inf

!if $(RMX3823_VENDOR_HW) == 1
  INF Binaries/qrd8550/QcomPkg/Drivers/UsbMsdDxe/UsbMsdDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/UsbDeviceDxe/UsbDeviceDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/UsbConfigDxe/UsbConfigDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/UsbInitDxe/UsbInitDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/UCDxe/UCDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/RNGDxe/RngDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/PILDxe/PILDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/PILProxyDxe/PILProxyDxe.inf
  INF Binaries/qrd8550/QcomPkg/Drivers/SPSSDxe/SPSSDxe.inf
!endif
