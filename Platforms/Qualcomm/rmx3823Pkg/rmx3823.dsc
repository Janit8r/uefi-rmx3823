##
#  Copyright (c) 2011 - 2022, ARM Limited. All rights reserved.
#  Copyright (c) 2014, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2020, Intel Corporation. All rights reserved.
#  Copyright (c) 2018, Bingxing Wang. All rights reserved.
#  Copyright (c) Microsoft Corporation.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
##

################################################################################
#
# realme GT5 240W (RMX3823) - SM8550 / kalama
#
# Derived from Platforms/Qualcomm/qrd8550Pkg (the SM8550 reference design),
# not from the Xiaomi nuwaPkg/shengPkg packages, because RMX3823 is a
# non-Xiaomi board and its ABL descends from the same Qualcomm boot_images
# baseline as QRD8550.
#
# Reused verbatim from QRD8550 on purpose:
#   - Binaries/qrd8550/* prebuilt Qualcomm DXE blobs (no rmx3823 set exists)
#   - Silicium-ACPI/Platforms/Qualcomm/qrd8550/AcpiTables.inf (no Realme
#     SM8550 ACPI package exists; the tables are SoC-generic)
#   - The DDR / register memory map in Library/MemoryMapLib/MemoryMapLib.c
#     (see the note in that file about what still needs device verification)
#
################################################################################

[Defines]
  PLATFORM_NAME                  = rmx3823
  PLATFORM_GUID                  = 7C4E1B92-3A5D-4F68-9E07-B2D1A8C53F14
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010005
  OUTPUT_DIRECTORY               = Build/rmx3823Pkg
  SUPPORTED_ARCHITECTURES        = AARCH64
  BUILD_TARGETS                  = RELEASE|DEBUG
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = rmx3823Pkg/rmx3823.fdf
  USE_CUSTOM_DISPLAY_DRIVER      = 0

  #
  # 0 = SM8550-AB
  # 1 = SM8550-AC
  #
  SOC_TYPE                       = 0

!include KailuaPkg/KailuaPkg.dsc.inc

[PcdsFixedAtBuild]
  #
  # DDR Memory
  #
  gArmTokenSpaceGuid.PcdSystemMemoryBase|0x80000000

  #
  # UEFI Stack
  #
  gArmPlatformTokenSpaceGuid.PcdCPUCoresStackBase|0xA760D000
  gArmPlatformTokenSpaceGuid.PcdCPUCorePrimaryStackSize|0x40000

  #
  # SMBIOS
  #
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemManufacturer|"realme"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemModel|"RMX3823"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemRetailModel|"RMX3823"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemRetailSku|"RMX3823"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemBoardModel|"RMX3823"

  #
  # Simple Frame Buffer
  #
  gSiliciumPkgTokenSpaceGuid.PcdFrameBufferWidth|1240
  gSiliciumPkgTokenSpaceGuid.PcdFrameBufferHeight|2772
  gSiliciumPkgTokenSpaceGuid.PcdFrameBufferColorDepth|32

  #
  # Platform PEI
  #
  gQcomPkgTokenSpaceGuid.PcdPlatformType|"LA"

[LibraryClasses]
  #
  # Memory Libraries
  #
  MemoryMapLib|rmx3823Pkg/Library/MemoryMapLib/MemoryMapLib.inf

  #
  # QCOM Libraries
  #
  ConfigurationMapLib|rmx3823Pkg/Library/ConfigurationMapLib/ConfigurationMapLib.inf

[Components]
  #
  # ACPI Tables
  #
  qrd8550/AcpiTables.inf
