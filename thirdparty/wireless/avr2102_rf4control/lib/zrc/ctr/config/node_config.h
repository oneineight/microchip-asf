/**
 * @file node_config.h
 *
 * @brief These are application-specific resources which are used
 *        in the example application of the coordinator in addition to the
 *        underlaying stack.
 *
 * Copyright (c) 2013-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */

/*
 * Copyright (c) 2014-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * Licensed under Atmel's Limited License Agreement --> EULA.txt
 */

/* Prevent double inclusion */
#ifndef NODE_CONFIG_H
#define NODE_CONFIG_H

/* === Includes ============================================================= */

#include "nwk_config.h"
#include "rf4ce.h"
#include "zrc.h"

/* === Macros =============================================================== */

/* === Types ================================================================ */

/* Configure RF4CE node capabilities */

/* The capabilities of this node. Implementation specific according to the
 * format
 * illustrated in Figure 26.
 * Implementation specific
 * NodeTypeTarget
 * NodeTypeController
 * PowerSourceMainsTrue
 * PowerSourceMainsFalse
 * SecurityCapableTrue
 * SecurityCapableFalse
 * ChannelNormalizationCapableTrue
 * ChannelNormalizationCapableFalse    */
#ifdef RF4CE_SECURITY
#define NWKC_NODE_CAPABILITIES   (NodeTypeController | PowerSourceMainsFalse \
	| SecurityCapableTrue | ChannelNormalizationCapableTrue)
#else
#define NWKC_NODE_CAPABILITIES   (NodeTypeController | PowerSourceMainsFalse \
	| SecurityCapableFalse | ChannelNormalizationCapableTrue)
#endif

#define NWKC_MAX_PAIRING_TABLE_ENTRIES    (5)
/* #define NWKC_VENDOR_IDENTIFIER           (0x1014) */

/* #define NWKC_VENDOR_STRING               "ATMEL  "          / * 7 characters
 * ! * / */

/* Implementation specific ZRC constant defines */
#ifdef ENABLE_PWR_SAVE_MODE
#define NWK_ACTIVE_PERIOD           nwkcMinActivePeriod /* 16.8 ms */
#else
#define NWK_ACTIVE_PERIOD           (0) /* 16.8 ms */
#endif
#define NWK_DUTY_CYCLE              nwkcMaxDutyCycle   /* 62500 symbols = 1s */
#define NWK_DISCOVERY_LQI_THRESHOLD (0x00)

/* === Externals ============================================================ */

/* === Prototypes =========================================================== */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* NODE_CONFIG_H */
/* EOF */
