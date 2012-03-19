/*
 *  Copyright (c) 2010 The WebM project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */


#ifndef tokenize_h
#define tokenize_h

#include "vp8/common/entropy.h"
#include "block.h"

void vp8_tokenize_initialize();

typedef struct
{
    short Token;
    short Extra;
} TOKENVALUE;

typedef struct
{
    const vp8_prob *context_tree;
    short           Extra;
    unsigned char   Token;
    unsigned char   skip_eob_node;
} TOKENEXTRA;

int rd_cost_mby(MACROBLOCKD *);

extern int mby_is_skippable(MACROBLOCKD *x,int has_y2_block);
extern int mbuv_is_skippable(MACROBLOCKD *x);
extern int mb_is_skippable(MACROBLOCKD *x,int has_y2_block);
extern int mby_is_skippable_8x8(MACROBLOCKD *x);
extern int mbuv_is_skippable_8x8(MACROBLOCKD *x);
extern int mb_is_skippable_8x8(MACROBLOCKD *x);

#ifdef ENTROPY_STATS
void init_context_counters();
void print_context_counters();

extern INT64 context_counters[BLOCK_TYPES] [COEF_BANDS] [PREV_COEF_CONTEXTS] [MAX_ENTROPY_TOKENS];
extern INT64 context_counters_8x8[BLOCK_TYPES] [COEF_BANDS] [PREV_COEF_CONTEXTS] [MAX_ENTROPY_TOKENS];

#if CONFIG_NEWENTROPY
void init_nzc_counters();
void print_nzc_counters();
extern INT64 nzc4x4y_counters[MAX_NZC_CONTEXTS][NZC4X4_TOKENS];
extern INT64 nzc4x4y2_counters[MAX_NZC_CONTEXTS][NZC4X4_TOKENS];
extern INT64 nzc4x4uv_counters[MAX_NZC_CONTEXTS][NZC4X4_TOKENS];
extern INT64 nzc8x8y_counters[MAX_NZC_CONTEXTS][NZC8X8_TOKENS];
extern INT64 nzc8x8uv_counters[MAX_NZC_CONTEXTS][NZC8X8_TOKENS];
extern INT64 nzc2x2y2_counters[MAX_NZC_CONTEXTS][NZC2X2_TOKENS];
void init_nzb_counters();
void print_nzb_counters();
extern INT64 nzby_counters[MAX_NZB_CONTEXTS][NZBY_TOKENS];
extern INT64 nzbuv_counters[MAX_NZB_CONTEXTS][NZBUV_TOKENS];
extern INT64 nzby2_counters[MAX_NZB_CONTEXTS][2];
void init_nzb2_counters();
void print_nzb2_counters();
extern INT64 nzb2y_counters[MAX_NZB_CONTEXTS][2];
extern INT64 nzb2uv_counters[MAX_NZB_CONTEXTS][2];
extern INT64 nzb2y2_counters[MAX_NZB_CONTEXTS][2];
#endif
#endif
extern const int *vp8_dct_value_cost_ptr;
/* TODO: The Token field should be broken out into a separate char array to
 *  improve cache locality, since it's needed for costing when the rest of the
 *  fields are not.
 */
extern const TOKENVALUE *vp8_dct_value_tokens_ptr;

#endif  /* tokenize_h */
