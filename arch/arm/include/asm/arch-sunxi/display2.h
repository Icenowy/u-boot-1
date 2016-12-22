/*
 * Sunxi platform display controller register and constant defines
 *
 * (C) Copyright 2016 Jernej Skrabec <jernej.skrabec@siol.net>
 *
 * Based on Linux DRM driver defines:
 * Copyright (C) 2016 Jean-Francois Moine <moinejf@free.fr>
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 * 
 * Based on display.h:
 * (C) Copyright 2014 Hans de Goede <hdegoede@redhat.com>
 * 
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef _SUNXI_DISPLAY2_H
#define _SUNXI_DISPLAY2_H

struct sunxi_lcdc_reg {
	u32 ctrl;			/* 0x00 */
	u32 int0;			/* 0x04 */
	u32 int1;			/* 0x08 */
	u8 res0[0x04];			/* 0x0c */
	u32 tcon0_frm_ctrl;		/* 0x10 */
	u32 tcon0_frm_seed[6];		/* 0x14 */
	u32 tcon0_frm_table[4];		/* 0x2c */
	u8 res1[4];			/* 0x3c */
	u32 tcon0_ctrl;			/* 0x40 */
	u32 tcon0_dclk;			/* 0x44 */
	u32 tcon0_timing_active;	/* 0x48 */
	u32 tcon0_timing_h;		/* 0x4c */
	u32 tcon0_timing_v;		/* 0x50 */
	u32 tcon0_timing_sync;		/* 0x54 */
	u32 tcon0_hv_intf;		/* 0x58 */
	u8 res2[0x04];			/* 0x5c */
	u32 tcon0_cpu_intf;		/* 0x60 */
	u32 tcon0_cpu_wr_dat;		/* 0x64 */
	u32 tcon0_cpu_rd_dat0;		/* 0x68 */
	u32 tcon0_cpu_rd_dat1;		/* 0x6c */
	u32 tcon0_ttl_timing0;		/* 0x70 */
	u32 tcon0_ttl_timing1;		/* 0x74 */
	u32 tcon0_ttl_timing2;		/* 0x78 */
	u32 tcon0_ttl_timing3;		/* 0x7c */
	u32 tcon0_ttl_timing4;		/* 0x80 */
	u32 tcon0_lvds_intf;		/* 0x84 */
	u32 tcon0_io_polarity;		/* 0x88 */
	u32 tcon0_io_tristate;		/* 0x8c */
	u32 tcon1_ctrl;			/* 0x90 */
	u32 tcon1_timing_source;	/* 0x94 */
	u32 tcon1_timing_scale;		/* 0x98 */
	u32 tcon1_timing_out;		/* 0x9c */
	u32 tcon1_timing_h;		/* 0xa0 */
	u32 tcon1_timing_v;		/* 0xa4 */
	u32 tcon1_timing_sync;		/* 0xa8 */
	u8 res3[0x44];			/* 0xac */
	u32 tcon1_io_polarity;		/* 0xf0 */
	u32 tcon1_io_tristate;		/* 0xf4 */
	u8 res4[0x108];			/* 0xf8 */
	u32 mux_ctrl;			/* 0x200 */};

/* global control */
struct de_glb {
	u32 ctl;
#define		DE_MUX_GLB_CTL_rt_en BIT(0)
	u32 status;
	u32 dbuff;
	u32 size;
};

/* alpha blending */
struct de_bld {
	u32 fcolor_ctl;			/* 00 */
	struct {
		u32 fcolor;
		u32 insize;
		u32 offset;
		u32 dum;
	} attr[4];
	u32 dum0[15];			/* (end of clear offset) */
	u32 route;			/* 80 */
	u32 premultiply;
	u32 bkcolor;
	u32 output_size;
	u32 bld_mode[4];
	u32 dum1[4];
	u32 ck_ctl;			/* b0 */
	u32 ck_cfg;
	u32 dum2[2];
	u32 ck_max[4];			/* c0 */
	u32 dum3[4];
	u32 ck_min[4];			/* e0 */
	u32 dum4[3];
	u32 out_ctl;			/* fc */
};

/* VI channel */
struct de_vi {
	struct {
		u32 attr;
#define			VI_CFG_ATTR_en BIT(0)
#define			VI_CFG_ATTR_fcolor_en BIT(4)
#define			VI_CFG_ATTR_fmt_SHIFT 8
#define			VI_CFG_ATTR_fmt_MASK GENMASK(12, 8)
#define			VI_CFG_ATTR_ui_sel BIT(15)
#define			VI_CFG_ATTR_top_down BIT(23)
		u32 size;
		u32 coord;
#define VI_N_PLANES 3
		u32 pitch[VI_N_PLANES];
		u32 top_laddr[VI_N_PLANES];
		u32 bot_laddr[VI_N_PLANES];
	} cfg[4];
	u32 fcolor[4];			/* c0 */
	u32 top_haddr[VI_N_PLANES];	/* d0 */
	u32 bot_haddr[VI_N_PLANES];	/* dc */
	u32 ovl_size[2];		/* e8 */
	u32 hori[2];			/* f0 */
	u32 vert[2];			/* f8 */
};

struct de_ui {
	struct {
		u32 attr;
#define			UI_CFG_ATTR_en BIT(0)
#define			UI_CFG_ATTR_alpmod_SHIFT 1
#define			UI_CFG_ATTR_alpmod_MASK GENMASK(2, 1)
#define			UI_CFG_ATTR_fcolor_en BIT(4)
#define			UI_CFG_ATTR_fmt_SHIFT 8
#define			UI_CFG_ATTR_fmt_MASK GENMASK(12, 8)
#define			UI_CFG_ATTR_top_down BIT(23)
#define			UI_CFG_ATTR_alpha_SHIFT 24
#define			UI_CFG_ATTR_alpha_MASK GENMASK(31, 24)
		u32 size;
		u32 coord;
		u32 pitch;
		u32 top_laddr;
		u32 bot_laddr;
		u32 fcolor;
		u32 dum;
	} cfg[4];			/* 00 */
	u32 top_haddr;			/* 80 */
	u32 bot_haddr;
	u32 ovl_size;			/* 88 */
};

struct sunxi_phy_hdmi_reg {
	u32 pol;
	u32 dum0[3];
	u32 read_en;
	u32 dum1[3];
	u32 ctrl;
	u32 unk1;
	u32 unk2;
	u32 pll;
	u32 clk;
	u32 unk3;
	u32 status;
};

/*
 * HDMI register addresses
 */
#define SUN8I_HDMI_PHY_BASE			(u32*)(SUNXI_HDMI_BASE + 0x10000)

#define SUN8I_HDMI_IH_I2CM_STAT0		(u32*)(SUNXI_HDMI_BASE + 0x0013)
#define SUN8I_HDMI_I2CM_SLAVE			(u32*)(SUNXI_HDMI_BASE + 0x0EE0)
#define SUN8I_HDMI_I2CM_ADDRESS			(u32*)(SUNXI_HDMI_BASE + 0x0EE1)
#define SUN8I_HDMI_I2CM_DATAI			(u32*)(SUNXI_HDMI_BASE + 0x8EE1)
#define SUN8I_HDMI_I2CM_OPERATION		(u32*)(SUNXI_HDMI_BASE + 0x0EE2)
#define SUN8I_HDMI_I2CM_INT			(u32*)(SUNXI_HDMI_BASE + 0x0EE3)
#define SUN8I_HDMI_I2CM_DIV			(u32*)(SUNXI_HDMI_BASE + 0x8EE3)
#define SUN8I_HDMI_I2CM_SEGADDR			(u32*)(SUNXI_HDMI_BASE + 0x4EE0)
#define SUN8I_HDMI_I2CM_SOFTRSTZ		(u32*)(SUNXI_HDMI_BASE + 0x4EE1)
#define SUN8I_HDMI_I2CM_SEGPTR			(u32*)(SUNXI_HDMI_BASE + 0xCEE0)
#define SUN8I_HDMI_I2CM_SS_SCL_HCNT_0_ADDR	(u32*)(SUNXI_HDMI_BASE + 0x4EE2)
#define SUN8I_HDMI_I2CM_SS_SCL_LCNT_0_ADDR	(u32*)(SUNXI_HDMI_BASE + 0xCEE2)

/*
 * DE register constants.
 */
/* TODO: move to appropriate place */
#define SUN8I_DE_BASE				0x01000000
#define SUN8I_DE_GATE_REG			(u32*)(SUN8I_DE_BASE + 0x0004)
#define SUN8I_DE_MOD_REG			(u32*)(SUN8I_DE_BASE + 0x0000)
#define SUN8I_DE_RESET_REG			(u32*)(SUN8I_DE_BASE + 0x0008)
#define SUN8I_DE_DIV_REG			(u32*)(SUN8I_DE_BASE + 0x000c)
#define SUN8I_DE_SEL_REG			(u32*)(SUN8I_DE_BASE + 0x0010)

#define DE_MUX0_BASE 				(u8*)(SUN8I_DE_BASE + 0x00100000)
/* MUX registers (addr / MUX base) */
#define DE_MUX_GLB_REGS 0x00000		/* global control */
#define DE_MUX_BLD_REGS 0x01000		/* alpha blending */
#define DE_MUX_CHAN_REGS 0x02000	/* VI/UI overlay channels */
#define		DE_MUX_CHAN_SZ 0x1000	/* size of a channel */
#define DE_MUX_VSU_REGS 0x20000		/* VSU */
#define DE_MUX_GSU1_REGS 0x30000	/* GSUs */
#define DE_MUX_GSU2_REGS 0x40000
#define DE_MUX_GSU3_REGS 0x50000
#define DE_MUX_FCE_REGS 0xa0000		/* FCE */
#define DE_MUX_BWS_REGS 0xa2000		/* BWS */
#define DE_MUX_LTI_REGS 0xa4000		/* LTI */
#define DE_MUX_PEAK_REGS 0xa6000	/* PEAK */
#define DE_MUX_ASE_REGS 0xa8000		/* ASE */
#define DE_MUX_FCC_REGS 0xaa000		/* FCC */
#define DE_MUX_DCSC_REGS 0xb0000 /* DCSC/SMBL */

#define DE2_FORMAT_ARGB_8888 0
#define DE2_FORMAT_BGRA_8888 3
#define DE2_FORMAT_XRGB_8888 4
#define DE2_FORMAT_RGB_888 8
#define DE2_FORMAT_BGR_888 9

/* coordinates and sizes */
#define XY(x, y) (((y) << 16) | (x))
#define WH(w, h) (((h - 1) << 16) | (w - 1))

/*
 * LCDC register constants.
 */
#define SUNXI_LCDC_X(x)				(((x) - 1) << 16)
#define SUNXI_LCDC_Y(y)				(((y) - 1) << 0)
#define SUNXI_LCDC_CTRL_TCON_ENABLE		(1 << 31)
#define SUNXI_LCDC_TCON0_CTRL_ENABLE		(1 << 31)
#define SUNXI_LCDC_TCON1_CTRL_CLK_DELAY(n)	(((n) & 0x1f) << 4)
#define SUNXI_LCDC_TCON1_CTRL_INTERLACE_ENABLE	(1 << 20)
#define SUNXI_LCDC_TCON1_CTRL_ENABLE		(1 << 31)
#define SUNXI_LCDC_TCON1_TIMING_H_BP(n)		(((n) - 1) << 0)
#define SUNXI_LCDC_TCON1_TIMING_H_TOTAL(n)	(((n) - 1) << 16)
#define SUNXI_LCDC_TCON1_TIMING_V_BP(n)		(((n) - 1) << 0)
#define SUNXI_LCDC_TCON1_TIMING_V_TOTAL(n)	((n) << 16)

/*
 * HDMI register constants.
 */
#define SUNXI_HDMI_HPD_DETECT			(1 << 19)

#define SUN8I_HMDI_DDC_CTRL_RESET		(1 << 0)
#define SUN8I_HMDI_DDC_ADDR_SLAVE_ADDR		(0x50 << 0)
#define SUN8I_HMDI_DDC_ADDR_SEG_ADDR		(0x30 << 0)


#endif /* _SUNXI_DISPLAY_H */
