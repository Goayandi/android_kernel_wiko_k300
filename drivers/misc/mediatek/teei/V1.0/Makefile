# Copyright (c) 2015-2016 MICROTRUST Incorporated
# All Rights Reserved.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# version 2 as published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.

$(info "CONFIG_MICROTRUST_TEE_SUPPORT=$(CONFIG_MICROTRUST_TEE_SUPPORT)")
$(info "CONFIG_MICROTRUST_TZ_DRIVER=$(CONFIG_MICROTRUST_TZ_DRIVER)")
$(info "CONFIG_MICROTRUST_VFS_DRIVER=$(CONFIG_MICROTRUST_VFS_DRIVER)")
$(info "CONFIG_MICROTRUST_FP_DRIVER=$(CONFIG_MICROTRUST_FP_DRIVER)")
$(info "CONFIG_MICROTRUST_TUI_DRIVER=$(CONFIG_MICROTRUST_TUI_DRIVER)")
$(info "CONFIG_MICROTRUST_DEBUG=$(CONFIG_MICROTRUST_DEBUG)")
$(info "CONFIG_MICROTRUST_DCIH_SUPPORT=$(CONFIG_MICROTRUST_DCIH_SUPPORT)")

subdir-ccflags-y  += -I$(srctree)/drivers/misc/mediatek/teei/V1.0/common/include

subdir-ccflags-$(CONFIG_MICROTRUST_DCIH_SUPPORT)  += \
	-I$(srctree)/drivers/misc/mediatek/teei/V1.0/tz_dcih \
	-I$(srctree)/drivers/misc/mediatek/teei/V1.0/public \
	-I$(srctree)/drivers/misc/mediatek/teei/V1.0/tz_driver/include

obj-$(CONFIG_MICROTRUST_TZ_DRIVER) += tz_driver/
obj-$(CONFIG_MICROTRUST_TZ_DRIVER) += gp_api/
obj-$(CONFIG_MICROTRUST_VFS_DRIVER) += tz_vfs/
obj-$(CONFIG_MICROTRUST_FP_DRIVER) += teei_fp/
obj-$(CONFIG_MICROTRUST_KEYMASTER_DRIVER) += ut_keymaster/
obj-$(CONFIG_MICROTRUST_TUI_DRIVER) += ut_tui/
obj-$(CONFIG_MICROTRUST_DCIH_SUPPORT) += tz_dcih/

# ifneq (,$(filter userdebug eng,$(TARGET_BUILD_VARIANT)))
# subdir-ccflags-y  += -DCONFIG_MICROTRUST_DEBUG
# endif
subdir-ccflags-y  += -DFP_TA_COMPATIBLE_SUPPORT