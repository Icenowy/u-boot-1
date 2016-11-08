/*
 * Sunxi platform display controller register and constant defines
 *
 * (C) Copyright 2016 Jernej Skrabec <jernej.skrabec@siol.net>
 *
 * Based on work by:
 * Copyright (C) 2016 Jean-Francois Moine <moinejf@free.fr>
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 * 
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef _SUNXI_DISPLAY_H
#define _SUNXI_DISPLAY_H

struct sun8i_lcdc_reg {
	u32 gctl;
	u32 gint0;
	u32 gint1;
	u32 dum0[13];
	u32 tcon0_ctl;				/* 0x40 */
	u32 dum1[19];
	u32 tcon1_ctl;				/* 0x90 */
	u32 basic0;			/* XI/YI */
	u32 basic1;			/* LS_XO/LS_YO */
	u32 basic2;			/* XO/YO */
	u32 basic3;			/* HT/HBP */
	u32 basic4;			/* VT/VBP */
	u32 basic5;			/* HSPW/VSPW */
	u32 dum2;
	u32 ps_sync;				/* 0xb0 */
	u32 dum3[15];
	u32 io_pol;				/* 0xf0 */
	u32 io_tri;
	u32 dum4[2];

	u32 ceu_ctl;				/* 0x100 */
	u32 dum5[3];
	u32 ceu_rr;
	u32 ceu_rg;
	u32 ceu_rb;
	u32 ceu_rc;
	u32 ceu_gr;
	u32 ceu_gg;
	u32 ceu_gb;
	u32 ceu_gc;
	u32 ceu_br;
	u32 ceu_bg;
	u32 ceu_bb;
	u32 ceu_bc;
	u32 ceu_rv;
	u32 ceu_gv;
	u32 ceu_bv;
	u32 dum6[45];

	u32 mux_ctl;				/* 0x200 */
	u32 dum7[63];

	u32 fill_ctl;				/* 0x300 */
	u32 fill_start0;
	u32 fill_end0;
	u32 fill_data0;
};

/* global control */
struct de_glb {
	u32 ctl;
#define		DE_MUX_GLB_CTL_rt_en BIT(0)
#define		DE_MUX_GLB_CTL_finish_irq_en BIT(4)
#define		DE_MUX_GLB_CTL_rtwb_port BIT(12)
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

#define HDMI_EDID_BLOCK_SIZE 			128

/*
 * HDMI register addresses
 */
#define SUN8I_HDMI_PHY_CTRL_REG			(u32*)(SUNXI_HDMI_BASE + 0x10020)
#define SUN8I_HDMI_PHY_UNK1_REG			(u32*)(SUNXI_HDMI_BASE + 0x10024)
#define SUN8I_HDMI_PHY_UNK2_REG			(u32*)(SUNXI_HDMI_BASE + 0x10028)
#define SUN8I_HDMI_PHY_PLL_REG			(u32*)(SUNXI_HDMI_BASE + 0x1002c)
#define SUN8I_HDMI_PHY_CLK_REG			(u32*)(SUNXI_HDMI_BASE + 0x10030)
#define SUN8I_HDMI_PHY_UNK3_REG			(u32*)(SUNXI_HDMI_BASE + 0x10034)
#define SUN8I_HDMI_PHY_STATUS_REG		(u32*)(SUNXI_HDMI_BASE + 0x10038)

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
#define SUN8I_TCON_GCTL_TCON_En			(1 << 31)
#define SUN8I_TCON_GINT0_TCON1_Vb_Int_En	(1 << 30)
#define SUN8I_TCON_GINT0_TCON1_Vb_Int_Flag	(1 << 14)
#define SUN8I_TCON0_CTL_TCON_En			(1 << 31)
#define SUN8I_TCON1_CTL_TCON_En			(1 << 31)
#define SUN8I_TCON1_CTL_Interlace_En		(1 << 20)
#define SUN8I_TCON1_CTL_Start_Delay_SHIFT	4
/*#define SUN8I_TCON1_CTL_Start_Delay_MASK	GENMASK(8, 4)*/
#define SUN8I_TCON1_IO_POL_IO0_inv		(1 << 24)
#define SUN8I_TCON1_IO_POL_IO1_inv		(1 << 25)
#define SUN8I_TCON1_IO_POL_IO2_inv		(1 << 26)
#define SUN8I_TCON_CEU_CTL_ceu_en		(1 << 31)

#define SUNXI_LCDC_X(x)				(((x) - 1) << 16)
#define SUNXI_LCDC_Y(y)				(((y) - 1) << 0)
#define SUNXI_LCDC_TCON_VSYNC_MASK		(1 << 24)
#define SUNXI_LCDC_TCON_HSYNC_MASK		(1 << 25)
#define SUNXI_LCDC_CTRL_IO_MAP_MASK		(1 << 0)
#define SUNXI_LCDC_CTRL_IO_MAP_TCON0		(0 << 0)
#define SUNXI_LCDC_CTRL_IO_MAP_TCON1		(1 << 0)
#define SUNXI_LCDC_CTRL_TCON_ENABLE		(1 << 31)
#define SUNXI_LCDC_TCON1_CTRL_SRC_BLUE		(1 << 1)
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
