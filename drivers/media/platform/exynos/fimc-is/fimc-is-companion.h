/*
 * Samsung Exynos5 SoC series FIMC-IS driver
 *
 * exynos5 fimc-is core functions
 *
 * Copyright (c) 2011 Samsung Electronics Co., Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifndef FIMC_IS_COMPANION_H
#define FIMC_IS_COMPANION_H

#include <linux/vmalloc.h>
#include <linux/firmware.h>

#include "fimc-is-core.h"
#include "fimc-is-companion_address.h"
#include "fimc-is-interface.h"

#define I2C_RETRY_COUNT         5
#define CRC_RETRY_COUNT         40

#define FIMC_IS_ISP_CV	"/data/ISP_CV"
#ifdef CONFIG_SOC_EXYNOS5433
#define USE_SPI
#endif

enum dcdc_vendor{
	DCDC_VENDOR_NONE = 0,
	DCDC_VENDOR_FAN53555,
	DCDC_VENDOR_NCP6335B,
};

struct dcdc_power {
	enum dcdc_vendor type;
	struct i2c_client *client;

	int (*get_vout_val)(int);
	int (*set_vout)(struct i2c_client *client, int vout);
};

int fimc_is_comp_is_valid(struct fimc_is_core *core);
int fimc_is_comp_loadfirm(struct fimc_is_core *core);
int fimc_is_comp_loadsetf(struct fimc_is_core *core);
int fimc_is_comp_loadcal(struct fimc_is_core *core);
u8 fimc_is_comp_is_compare_ver(struct fimc_is_core *core);
int fimc_is_power_binning(struct fimc_is_core *core);
void fimc_is_s_int_comb_isp(struct fimc_is_core *core,bool on, u32 ch);

#endif /* FIMC_IS_COMPANION_H */
