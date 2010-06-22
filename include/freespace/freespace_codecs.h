/*
 * This file is part of libfreespace.
 * 
 * Copyright (c) 2009-2010 Hillcrest Laboratories, Inc. 
 *
 * libfreespace is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef FREESPACE_CODECS_H_
#define FREESPACE_CODECS_H_

#include "freespace/freespace_common.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @defgroup messages Freespace Messages
 *
 * This page describes the messages that can be sent to and from the Freespace Device.
 * They are represented as structs which can be encoded and decoded from strings.
 */
/** @ingroup messages 
 * Reserved for passing message through from the Freespace coprocessor to the USB host.
 */
struct freespace_CoprocessorOutReport {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */

	uint8_t payloadLength;
	uint8_t payload[14];
};


/** @ingroup messages
 * Encode a CoprocessorOutReport message.
 *
 * @param s the freespace_CoprocessorOutReport struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeCoprocessorOutReport(const struct freespace_CoprocessorOutReport* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * Used for passing messages through from the USB host to the Freespace coprocessor interface.
 */
struct freespace_CoprocessorInReport {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */

	uint8_t payloadLength;
	uint8_t payload[14];
};


/** @ingroup messages
 * Decode a CoprocessorInReport message. Fill out the corresponding values in struct s.
 *
 * @param message the message to decode that was received from the Freespace device
 * @param length the length of the received message
 * @param s the preallocated freespace_CoprocessorInReport struct to decode into
 * @param ver the protocol version to use for this message
 * @return FREESPACE_SUCCESS or an error
 */
LIBFREESPACE_API int freespace_decodeCoprocessorInReport(const uint8_t* message, int length, struct freespace_CoprocessorInReport* s, uint8_t ver);

/** @ingroup messages 
 * Used by the host to put the dongle into pairing mode.
 */
struct freespace_PairingMessage {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */

};


/** @ingroup messages
 * Encode a PairingMessage message.
 *
 * @param s the freespace_PairingMessage struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodePairingMessage(const struct freespace_PairingMessage* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * This is sent from the host to the attached device(dongle) to request the product ID information. The dongle will forward this request to the Loop.
 */
struct freespace_ProductIDRequest {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */

};


/** @ingroup messages
 * Encode a ProductIDRequest message.
 *
 * @param s the freespace_ProductIDRequest struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeProductIDRequest(const struct freespace_ProductIDRequest* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * This request causes the Loop or dongle to set a status LED to a particular value
 */
struct freespace_LEDSetRequest {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** WP160: 0-Off, 1-On, 2-Release, FSAP160: 0-cause0, 1-cause1, 2-cause2 */
	uint8_t onOff;

	/** LED Select: 0-green(all devices)
	 1-red(all devices)
	 2-yellow(all devices)
	 3-blue(all devices)
	 4-FTA green
	 5-FTA red
	 6-S2U yellow
	 7-S2U blue
	 8-Dominion LED PWM
	 9-Dominion LED1
	 10-Dominion LED2
	 11-RFT LED A
	 12-RFT LED B */
	uint8_t selectLED;
};


/** @ingroup messages
 * Encode a LEDSetRequest message.
 *
 * @param s the freespace_LEDSetRequest struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeLEDSetRequest(const struct freespace_LEDSetRequest* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * Controls link quality status reporting
 */
struct freespace_LinkQualityRequest {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** 0: disable status messages, 1: enable status messages */
	uint8_t enable;
};


/** @ingroup messages
 * Encode a LinkQualityRequest message.
 *
 * @param s the freespace_LinkQualityRequest struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeLinkQualityRequest(const struct freespace_LinkQualityRequest* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * This message forces the Loop into an always on state. It is relayed to the Loop from the dongle.
 */
struct freespace_AlwaysOnRequest {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */

};


/** @ingroup messages
 * Encode a AlwaysOnRequest message.
 *
 * @param s the freespace_AlwaysOnRequest struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeAlwaysOnRequest(const struct freespace_AlwaysOnRequest* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * This message causes the RF frequencies of the selected device to be fixed at channels 0-4. The last byte selects the device.
	 When the loop is selected it is put into a mode where it does not require the dongle to transmit and where it does not go to sleep.
 */
struct freespace_FrequencyFixRequest {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */

	uint8_t channel0;
	uint8_t channel1;
	uint8_t channel2;
	uint8_t channel3;
	uint8_t channel4;

	/** 1 for dongle, 2 for loop */
	uint8_t device;
};


/** @ingroup messages
 * Encode a FrequencyFixRequest message.
 *
 * @param s the freespace_FrequencyFixRequest struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeFrequencyFixRequest(const struct freespace_FrequencyFixRequest* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * This message causes the dongle to reset itself.
 */
struct freespace_SoftwareResetMessage {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** 1 for dongle */
	uint8_t device;
};


/** @ingroup messages
 * Encode a SoftwareResetMessage message.
 *
 * @param s the freespace_SoftwareResetMessage struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeSoftwareResetMessage(const struct freespace_SoftwareResetMessage* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * This message disables the RF on the dongle.
 */
struct freespace_DongleRFDisableMessage {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */

};


/** @ingroup messages
 * Encode a DongleRFDisableMessage message.
 *
 * @param s the freespace_DongleRFDisableMessage struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeDongleRFDisableMessage(const struct freespace_DongleRFDisableMessage* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * This message disables the RF transmission on the dongle.
 */
struct freespace_TxDisableMessage {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */

};


/** @ingroup messages
 * Encode a TxDisableMessage message.
 *
 * @param s the freespace_TxDisableMessage struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeTxDisableMessage(const struct freespace_TxDisableMessage* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * This message is for RF Home frequency supression on the dongle.

	802.11 defines the peak of a channel to cover the range +-11MHz from the center frequency of the channel.
	Hillcrest adds an extra 1MHz to this boundary, so Low and High should be -12MHz from the center channel of the 802.11
	and +12MHz from the center channel of 802.11 respectively. These values must be in the range [1,82].
	To disable home frequency suppression, set either Low or High to be out-of-range. 0xFF is the preferred value for disabling suppression.
 */
struct freespace_DongleRFSupressHomeFrequencyMessage {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */

	uint8_t low;
	uint8_t high;
};


/** @ingroup messages
 * Encode a DongleRFSupressHomeFrequencyMessage message.
 *
 * @param s the freespace_DongleRFSupressHomeFrequencyMessage struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeDongleRFSupressHomeFrequencyMessage(const struct freespace_DongleRFSupressHomeFrequencyMessage* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * This is sent from dongle towards the loop to request flash record to be sent.
	The data sent starts from the word offset and continues through to the end of the record.
 */
struct freespace_FRSLoopReadRequest {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** Offset from start of record to begin reading. */
	uint16_t wordOffset;

	/** FRS record type to read. */
	uint16_t FRStype;

	/** Number of 32-bit words to read. */
	uint16_t BlockSize;
};


/** @ingroup messages
 * Encode a FRSLoopReadRequest message.
 *
 * @param s the freespace_FRSLoopReadRequest struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeFRSLoopReadRequest(const struct freespace_FRSLoopReadRequest* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * This is sent from the host towards the loop to initiate a flash record write.
	A length of 0 will cause the record to be invalidated.
 */
struct freespace_FRSLoopWriteRequest {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** Length in 32-bit words of record to be written. */
	uint16_t length;

	/** FRS record type to read. */
	uint16_t FRStype;
};


/** @ingroup messages
 * Encode a FRSLoopWriteRequest message.
 *
 * @param s the freespace_FRSLoopWriteRequest struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeFRSLoopWriteRequest(const struct freespace_FRSLoopWriteRequest* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * This message is sent from the host towards the loop to write data to the record a previous write request indicated.
 */
struct freespace_FRSLoopWriteData {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** Offset from start of record to write data. */
	uint16_t wordOffset;

	/** 32-bit word to write. */
	uint32_t data;
};


/** @ingroup messages
 * Encode a FRSLoopWriteData message.
 *
 * @param s the freespace_FRSLoopWriteData struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeFRSLoopWriteData(const struct freespace_FRSLoopWriteData* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * Undocumented Message
 */
struct freespace_FRSDongleReadRequest {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** Offset from start of record to begin reading. */
	uint16_t wordOffset;

	/** FRS record type to read. */
	uint16_t FRStype;

	/** Number of 32-bit words to read. */
	uint16_t BlockSize;
};


/** @ingroup messages
 * Encode a FRSDongleReadRequest message.
 *
 * @param s the freespace_FRSDongleReadRequest struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeFRSDongleReadRequest(const struct freespace_FRSDongleReadRequest* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * Undocumented Message
 */
struct freespace_FRSDongleWriteRequest {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** Length in 32-bit words of record to be written. */
	uint16_t length;

	/** FRS record type to read. */
	uint16_t FRStype;
};


/** @ingroup messages
 * Encode a FRSDongleWriteRequest message.
 *
 * @param s the freespace_FRSDongleWriteRequest struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeFRSDongleWriteRequest(const struct freespace_FRSDongleWriteRequest* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * Undocumented Message
 */
struct freespace_FRSDongleWriteData {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** Offset from start of record to write data. */
	uint16_t wordOffset;

	/** 32-bit word to write. */
	uint32_t data;
};


/** @ingroup messages
 * Encode a FRSDongleWriteData message.
 *
 * @param s the freespace_FRSDongleWriteData struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeFRSDongleWriteData(const struct freespace_FRSDongleWriteData* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * Undocumented Message
 */
struct freespace_FRSEFlashReadRequest {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** Offset from start of record to begin reading. */
	uint16_t wordOffset;

	/** FRS record type to read. */
	uint16_t FRStype;

	/** Number of 32-bit words to read. */
	uint16_t BlockSize;
};


/** @ingroup messages
 * Encode a FRSEFlashReadRequest message.
 *
 * @param s the freespace_FRSEFlashReadRequest struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeFRSEFlashReadRequest(const struct freespace_FRSEFlashReadRequest* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * Undocumented Message
 */
struct freespace_FRSEFlashWriteRequest {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** Length in 32-bit words of record to be written. */
	uint16_t length;

	/** FRS record type to read. */
	uint16_t FRStype;
};


/** @ingroup messages
 * Encode a FRSEFlashWriteRequest message.
 *
 * @param s the freespace_FRSEFlashWriteRequest struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeFRSEFlashWriteRequest(const struct freespace_FRSEFlashWriteRequest* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * Undocumented Message
 */
struct freespace_FRSEFlashWriteData {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** Offset from start of record to write data. */
	uint16_t wordOffset;

	/** 32-bit word to write. */
	uint32_t data;
};


/** @ingroup messages
 * Encode a FRSEFlashWriteData message.
 *
 * @param s the freespace_FRSEFlashWriteData struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeFRSEFlashWriteData(const struct freespace_FRSEFlashWriteData* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * This message enables the RF on the dongle.
 */
struct freespace_DongleRFEnableMessage {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */

};


/** @ingroup messages
 * Encode a DongleRFEnableMessage message.
 *
 * @param s the freespace_DongleRFEnableMessage struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeDongleRFEnableMessage(const struct freespace_DongleRFEnableMessage* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * This report controls the behavior of the Freespace motion reports. The unused bits are reserved for future features.
 */
struct freespace_DataModeRequest {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** Enable Body Motion: when set to 1 enables Body Frame Motion reports. */
	uint8_t enableBodyMotion;

	/** Enable User Position: when set to 1 enables User Frame Position reports */
	uint8_t enableUserPosition;

	/** Inhibit Power Manager: when set to 1 disables the power management feature that automatically stops sending motion reports after a period of no motion. */
	uint8_t inhibitPowerManager;

	/** Enable Mouse Movement: when set to 1 enables Mouse Movement reports. */
	uint8_t enableMouseMovement;

	/** Disable Freespace: when set to 1 disables the Freespace motion sensing system to conserve power. No pointer or motion reports are sent regardless of the value of the other bits. */
	uint8_t disableFreespace;

	/** Reserved for testing, */
	uint8_t SDA;

	/** Report current data mode: when set to causes a doata mode repsones message to be generated but does not update data mode. */
	uint8_t status;

	/** Aggregate: when set, if both Body Frame and User frame are enabled, send them as a BodyUser message, which combines the two.  */
	uint8_t aggregate;
};


/** @ingroup messages
 * Encode a DataModeRequest message.
 *
 * @param s the freespace_DataModeRequest struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeDataModeRequest(const struct freespace_DataModeRequest* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * Configures button test mode for manufacturing test station.
 */
struct freespace_ButtonTestModeRequest {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** 0: exit button test mode. 1: enter button test mode. */
	uint8_t enable;
};


/** @ingroup messages
 * Encode a ButtonTestModeRequest message.
 *
 * @param s the freespace_ButtonTestModeRequest struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeButtonTestModeRequest(const struct freespace_ButtonTestModeRequest* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * Pairing response is used to either respond to pairing requests from the host or to send pairing status updates to the host that describe events during the pairing process.
 */
struct freespace_PairingResponse {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** 0: not pairing.
	 1: pairing */
	uint8_t pairing;

	/** 0: dongle is not in auto-pairing
	1: dongle is in auto-pairing */
	uint8_t autoPairing;

	/** 0: not successful or still in progress
	1: successful */
	uint8_t success;
};


/** @ingroup messages
 * Decode a PairingResponse message. Fill out the corresponding values in struct s.
 *
 * @param message the message to decode that was received from the Freespace device
 * @param length the length of the received message
 * @param s the preallocated freespace_PairingResponse struct to decode into
 * @param ver the protocol version to use for this message
 * @return FREESPACE_SUCCESS or an error
 */
LIBFREESPACE_API int freespace_decodePairingResponse(const uint8_t* message, int length, struct freespace_PairingResponse* s, uint8_t ver);

/** @ingroup messages 
 * This is sent from the polled device towards the host to convey the product ID information.
 */
struct freespace_ProductIDResponse {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */

	uint32_t swPartNumber;
	uint32_t swBuildNumber;
	uint32_t swicn;
	uint16_t swVersionPatch;
	uint8_t swVersionMinor;
	uint8_t swVersionMajor;
	uint32_t serialNumber;

	/** The device class represents the characteristics of the device providing the product ID. 
	 0: device type not known.
	 1: non-data-generating device.
	 2: data-generating device. */
	int deviceClass;

	/** 0: read serial number is valid, 1 read serial number is invalid; retry read until valid. */
	uint8_t invalidNS;

	/** The device has just started up. This bit self clears after the first message is sent. */
	uint8_t startup;
};


/** @ingroup messages
 * Decode a ProductIDResponse message. Fill out the corresponding values in struct s.
 *
 * @param message the message to decode that was received from the Freespace device
 * @param length the length of the received message
 * @param s the preallocated freespace_ProductIDResponse struct to decode into
 * @param ver the protocol version to use for this message
 * @return FREESPACE_SUCCESS or an error
 */
LIBFREESPACE_API int freespace_decodeProductIDResponse(const uint8_t* message, int length, struct freespace_ProductIDResponse* s, uint8_t ver);

/** @ingroup messages 
 * This message is sent from a compliance test-ready dongle to indicate the dongle's current status.
 */
struct freespace_LinkStatus {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** 0: bad
	1: good */
	uint8_t status;

	/** 0: normal operation
	1: fixed frequency operation
	2: RF disabled */
	uint8_t mode;

	/** 0: did not occur
	1: occurred. Self clears. */
	uint8_t resetStatus;

	/** 0: TX is enabled
	1: TX is disabled. */
	uint8_t txDisabled;
};


/** @ingroup messages
 * Decode a LinkStatus message. Fill out the corresponding values in struct s.
 *
 * @param message the message to decode that was received from the Freespace device
 * @param length the length of the received message
 * @param s the preallocated freespace_LinkStatus struct to decode into
 * @param ver the protocol version to use for this message
 * @return FREESPACE_SUCCESS or an error
 */
LIBFREESPACE_API int freespace_decodeLinkStatus(const uint8_t* message, int length, struct freespace_LinkStatus* s, uint8_t ver);

/** @ingroup messages 
 * This message is sent from a the loop to acknowledge an always on mode request message.
 */
struct freespace_AlwaysOnResponse {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */

};


/** @ingroup messages
 * Decode a AlwaysOnResponse message. Fill out the corresponding values in struct s.
 *
 * @param message the message to decode that was received from the Freespace device
 * @param length the length of the received message
 * @param s the preallocated freespace_AlwaysOnResponse struct to decode into
 * @param ver the protocol version to use for this message
 * @return FREESPACE_SUCCESS or an error
 */
LIBFREESPACE_API int freespace_decodeAlwaysOnResponse(const uint8_t* message, int length, struct freespace_AlwaysOnResponse* s, uint8_t ver);

/** @ingroup messages 
 * This is sent from the loop to the host to convey an FRS record.
 */
struct freespace_FRSLoopReadResponse {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** Word Offset indicates the number of words the data is offset from the beginning of the record */
	uint16_t wordOffset;
	uint32_t data[5];

	/** Status:
	0: no error
	1: unrecognized FRS type
	2: busy
	3: read completed
	4: offset out of range
	5: record empty
	6: read block completed
	7: read block completed and read reacord completed */
	int status;

	/** Data Length indicates the number of data words contained within the message, typically 5 words */
	int dataLength;

	/** FRS record type */
	uint16_t FRStype;
};


/** @ingroup messages
 * Decode a FRSLoopReadResponse message. Fill out the corresponding values in struct s.
 *
 * @param message the message to decode that was received from the Freespace device
 * @param length the length of the received message
 * @param s the preallocated freespace_FRSLoopReadResponse struct to decode into
 * @param ver the protocol version to use for this message
 * @return FREESPACE_SUCCESS or an error
 */
LIBFREESPACE_API int freespace_decodeFRSLoopReadResponse(const uint8_t* message, int length, struct freespace_FRSLoopReadResponse* s, uint8_t ver);

/** @ingroup messages 
 * This is sent from the loop to the host to indicate status of the write operation.
 */
struct freespace_FRSLoopWriteResponse {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */

	uint16_t wordOffset;

	/** Status/Error:
	0: word received
	1: unrecognized FRS type
	2: busy
	3: write completed
	4: write mode entered already
	5: write failed
	6: data received while not in write mode
	7: invalid length
	8: record valid (the complete record passed internal validation checks)
	9:record invalid (the complete record failed internal validation checks) */
	uint8_t status;
};


/** @ingroup messages
 * Decode a FRSLoopWriteResponse message. Fill out the corresponding values in struct s.
 *
 * @param message the message to decode that was received from the Freespace device
 * @param length the length of the received message
 * @param s the preallocated freespace_FRSLoopWriteResponse struct to decode into
 * @param ver the protocol version to use for this message
 * @return FREESPACE_SUCCESS or an error
 */
LIBFREESPACE_API int freespace_decodeFRSLoopWriteResponse(const uint8_t* message, int length, struct freespace_FRSLoopWriteResponse* s, uint8_t ver);

/** @ingroup messages 
 * This is sent from the dongle to the host to convey an FRS record.
 */
struct freespace_FRSDongleReadResponse {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** Word Offset indicates the number of words the data is offset from the beginning of the record */
	uint16_t wordOffset;
	uint32_t data[5];

	/** Status:
	0: no error
	1: unrecognized FRS type
	2: busy
	3: read completed
	4: offset out of range
	5: record empty
	6: read block completed
	7: read block completed and read reacord completed */
	int status;

	/** Data Length indicates the number of data words contained within the message, typically 5 words */
	int dataLength;

	/** FRS record type */
	uint16_t FRStype;
};


/** @ingroup messages
 * Decode a FRSDongleReadResponse message. Fill out the corresponding values in struct s.
 *
 * @param message the message to decode that was received from the Freespace device
 * @param length the length of the received message
 * @param s the preallocated freespace_FRSDongleReadResponse struct to decode into
 * @param ver the protocol version to use for this message
 * @return FREESPACE_SUCCESS or an error
 */
LIBFREESPACE_API int freespace_decodeFRSDongleReadResponse(const uint8_t* message, int length, struct freespace_FRSDongleReadResponse* s, uint8_t ver);

/** @ingroup messages 
 * This is sent from the dongle to the host to indicate status of the write operation.
 */
struct freespace_FRSDongleWriteResponse {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */

	uint16_t wordOffset;

	/** Status/Error:
	0: word received
	1: unrecognized FRS type
	2: busy
	3: write completed
	4: write mode entered already
	5: write failed
	6: data received while not in write mode
	7: invalid length
	8: record valid (the complete record passed internal validation checks)
	9:record invalid (the complete record failed internal validation checks) */
	uint8_t status;
};


/** @ingroup messages
 * Decode a FRSDongleWriteResponse message. Fill out the corresponding values in struct s.
 *
 * @param message the message to decode that was received from the Freespace device
 * @param length the length of the received message
 * @param s the preallocated freespace_FRSDongleWriteResponse struct to decode into
 * @param ver the protocol version to use for this message
 * @return FREESPACE_SUCCESS or an error
 */
LIBFREESPACE_API int freespace_decodeFRSDongleWriteResponse(const uint8_t* message, int length, struct freespace_FRSDongleWriteResponse* s, uint8_t ver);

/** @ingroup messages 
 * This is sent from the loop to the host to convey an FRS record.
 */
struct freespace_FRSEFlashReadResponse {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** Word Offset indicates the number of words the data is offset from the beginning of the record */
	uint16_t wordOffset;
	uint32_t data[5];

	/** Status:
	0: no error
	1: unrecognized FRS type
	2: busy
	3: read completed
	4: offset out of range
	5: record empty
	6: read block completed
	7: read block completed and read reacord completed */
	int status;

	/** Data Length indicates the number of data words contained within the message, typically 5 words */
	int dataLength;

	/** FRS record type */
	uint16_t FRStype;
};


/** @ingroup messages
 * Decode a FRSEFlashReadResponse message. Fill out the corresponding values in struct s.
 *
 * @param message the message to decode that was received from the Freespace device
 * @param length the length of the received message
 * @param s the preallocated freespace_FRSEFlashReadResponse struct to decode into
 * @param ver the protocol version to use for this message
 * @return FREESPACE_SUCCESS or an error
 */
LIBFREESPACE_API int freespace_decodeFRSEFlashReadResponse(const uint8_t* message, int length, struct freespace_FRSEFlashReadResponse* s, uint8_t ver);

/** @ingroup messages 
 * Undocumented Message
 */
struct freespace_FRSEFlashWriteResponse {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */

	uint16_t wordOffset;

	/** Status/Error:
	0: word received
	1: unrecognized FRS type
	2: busy
	3: write completed
	4: write mode entered already
	5: write failed
	6: data received while not in write mode
	7: invalid length
	8: record valid (the complete record passed internal validation checks)
	9:record invalid (the complete record failed internal validation checks) */
	uint8_t status;
};


/** @ingroup messages
 * Decode a FRSEFlashWriteResponse message. Fill out the corresponding values in struct s.
 *
 * @param message the message to decode that was received from the Freespace device
 * @param length the length of the received message
 * @param s the preallocated freespace_FRSEFlashWriteResponse struct to decode into
 * @param ver the protocol version to use for this message
 * @return FREESPACE_SUCCESS or an error
 */
LIBFREESPACE_API int freespace_decodeFRSEFlashWriteResponse(const uint8_t* message, int length, struct freespace_FRSEFlashWriteResponse* s, uint8_t ver);

/** @ingroup messages 
 * This report acknowledges the last DataModeRequest received by the dongle.
 */
struct freespace_DataModeResponse {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** Enable Body Motion: when set to 1 Body Frame Motion reports are enabled. */
	uint8_t enableBodyMotion;

	/** Enable User Position: when set to 1 User Frame Position reports are enabled */
	uint8_t enableUserPosition;

	/** Inhibit Power Manager: when set to 1 the power management feature isinhibited. */
	uint8_t inhibitPowerManager;

	/** Enable Mouse Movement: when set to 1 Mouse Movement reports are enabled. */
	uint8_t enableMouseMovement;

	/** Disable Freespace: when set to 1 the Freespace motion sensing system disabled. */
	uint8_t disableFreespace;

	/** Reserved for testing, */
	uint8_t SDA;

	/** Aggregate: when set, if both Body Frame and User frame are enabled, send them as a BodyUser message, which combines the two.  */
	uint8_t aggregate;
};


/** @ingroup messages
 * Decode a DataModeResponse message. Fill out the corresponding values in struct s.
 *
 * @param message the message to decode that was received from the Freespace device
 * @param length the length of the received message
 * @param s the preallocated freespace_DataModeResponse struct to decode into
 * @param ver the protocol version to use for this message
 * @return FREESPACE_SUCCESS or an error
 */
LIBFREESPACE_API int freespace_decodeDataModeResponse(const uint8_t* message, int length, struct freespace_DataModeResponse* s, uint8_t ver);

/** @ingroup messages 
 * Report button status changes and acknowledge button mode request message.
 */
struct freespace_ButtonTestModeResponse {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** 0: ack exit test mode. 1: ack enter test mode.  2: button update. */
	uint8_t status;

	/** 0 - 15: number of button pressed or released.  Only valid when status = update. */
	uint8_t button;

	/** 0: button released. 1: button pressed.  Only valid when status = update. */
	uint8_t press;
};


/** @ingroup messages
 * Decode a ButtonTestModeResponse message. Fill out the corresponding values in struct s.
 *
 * @param message the message to decode that was received from the Freespace device
 * @param length the length of the received message
 * @param s the preallocated freespace_ButtonTestModeResponse struct to decode into
 * @param ver the protocol version to use for this message
 * @return FREESPACE_SUCCESS or an error
 */
LIBFREESPACE_API int freespace_decodeButtonTestModeResponse(const uint8_t* message, int length, struct freespace_ButtonTestModeResponse* s, uint8_t ver);

/** @ingroup messages 
 * Sent by the host to request the battery status of the handheld unit.
 */
struct freespace_BatteryLevelRequest {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */

};


/** @ingroup messages
 * Encode a BatteryLevelRequest message.
 *
 * @param s the freespace_BatteryLevelRequest struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeBatteryLevelRequest(const struct freespace_BatteryLevelRequest* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * Indicates the battery strength of the handheld unit.
 */
struct freespace_BatteryLevel {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** A percentage of the operating voltage range (0-100%) */
	uint8_t batteryStrength;
};


/** @ingroup messages
 * Decode a BatteryLevel message. Fill out the corresponding values in struct s.
 *
 * @param message the message to decode that was received from the Freespace device
 * @param length the length of the received message
 * @param s the preallocated freespace_BatteryLevel struct to decode into
 * @param ver the protocol version to use for this message
 * @return FREESPACE_SUCCESS or an error
 */
LIBFREESPACE_API int freespace_decodeBatteryLevel(const uint8_t* message, int length, struct freespace_BatteryLevel* s, uint8_t ver);

/** @ingroup messages 
 * Conveys the motion relative to the body frame of the Freespace handheld device. 
 The data have been processed to remove tremor and other unwanted side effects.
 */
struct freespace_BodyFrame {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** Button bits. */
	uint8_t button1;
	uint8_t button2;
	uint8_t button3;
	uint8_t button4;
	uint8_t button5;
	uint8_t button6;
	uint8_t button7;
	uint8_t button8;

	/** X pointer movement. */
	int8_t deltaX;

	/** Y pointer movement. */
	int8_t deltaY;

	/** Scroll wheel movement. */
	int8_t deltaWheel;

	/** A monotonically increasing integer generated by the Freespace sensor board at a nominal rate of 125 Hz.
	Can be used to correlate body frame messages with the user frame messages */
	uint16_t sequenceNumber;

	/** Linear Acceleration is reported in SI units (cm/s^2) with an exponent of -1. X is positive forward. Y is positive right. Z is positive down wrt handheld frame of reference. */
	int16_t linearAccelX;
	int16_t linearAccelY;
	int16_t linearAccelZ;

	/** Angular Velocity is reported in units of rad/s with an exponent of -3. X positive is tilt right(roll). Y positive it tilt up(pitch). Z positive is turn right(yaw) wrt the handheld device frame of reference. */
	int16_t angularVelX;
	int16_t angularVelY;
	int16_t angularVelZ;
};


/** @ingroup messages
 * Decode a BodyFrame message. Fill out the corresponding values in struct s.
 *
 * @param message the message to decode that was received from the Freespace device
 * @param length the length of the received message
 * @param s the preallocated freespace_BodyFrame struct to decode into
 * @param ver the protocol version to use for this message
 * @return FREESPACE_SUCCESS or an error
 */
LIBFREESPACE_API int freespace_decodeBodyFrame(const uint8_t* message, int length, struct freespace_BodyFrame* s, uint8_t ver);

/** @ingroup messages 
 * Conveys the handheld device position and orientation with respect to a user frame of reference.
 */
struct freespace_UserFrame {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** Button bits. */
	uint8_t button1;
	uint8_t button2;
	uint8_t button3;
	uint8_t button4;
	uint8_t button5;
	uint8_t button6;
	uint8_t button7;
	uint8_t button8;

	/** X pointer movement. */
	int8_t deltaX;

	/** Y pointer movement. */
	int8_t deltaY;

	/** Scroll wheel movement. */
	int8_t deltaWheel;

	/** Correlates the position report with the Body Frame Motion Report */
	uint16_t sequenceNumber;

	/** Linear Offset is in units of meters. X positive is right. Y positive is near. Z positive is down wrt the user frame of reference. */
	int16_t linearPosX;
	int16_t linearPosY;
	int16_t linearPosZ;

	/** Angular Position is in dimensionless units. The axes are given in quaternion form where A, B, C, D represent the real, i, j, and k coefficients. */
	int16_t angularPosA;
	int16_t angularPosB;
	int16_t angularPosC;
	int16_t angularPosD;
};


/** @ingroup messages
 * Decode a UserFrame message. Fill out the corresponding values in struct s.
 *
 * @param message the message to decode that was received from the Freespace device
 * @param length the length of the received message
 * @param s the preallocated freespace_UserFrame struct to decode into
 * @param ver the protocol version to use for this message
 * @return FREESPACE_SUCCESS or an error
 */
LIBFREESPACE_API int freespace_decodeUserFrame(const uint8_t* message, int length, struct freespace_UserFrame* s, uint8_t ver);

/** @ingroup messages 
 * DEPRECATED: This report controls the behavior of the Freespace motion reports. The unused bits are reserved for future features.
 */
struct freespace_DataMotionControl {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** Enable Body Motion: when set to 1 enables Body Frame Motion reports. */
	uint8_t enableBodyMotion;

	/** Enable User Position: when set to 1 enables User Frame Position reports */
	uint8_t enableUserPosition;

	/** Inhibit Power Manager: when set to 1 disables the power management feature that automatically stops sending motion reports after a period of no motion. */
	uint8_t inhibitPowerManager;

	/** Enable Mouse Movement: when set to 1 enables Mouse Movement reports. */
	uint8_t enableMouseMovement;

	/** Disable Freespace: when set to 1 disables the Freespace motion sensing system to conserve power. No pointer or motion reports are sent regardless of the value of the other bits. */
	uint8_t disableFreespace;
};


/** @ingroup messages
 * Encode a DataMotionControl message.
 *
 * @param s the freespace_DataMotionControl struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeDataMotionControl(const struct freespace_DataMotionControl* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * This is sent from the device to the host to indicate status of the write operation.
 */
struct freespace_FRSWriteResponse {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** Status/Error:
	0: word received
	1: unrecognized FRS type
	2: busy
	3: write completed
	4: write mode entered already
	5: write failed
	6: data received while not in write mode
	7: invalid length
	8: record valid (the complete record passed internal validation checks)
	9:record invalid (the complete record failed internal validation checks) */
	uint8_t status;
	uint16_t wordOffset;
};


/** @ingroup messages
 * Decode a FRSWriteResponse message. Fill out the corresponding values in struct s.
 *
 * @param message the message to decode that was received from the Freespace device
 * @param length the length of the received message
 * @param s the preallocated freespace_FRSWriteResponse struct to decode into
 * @param ver the protocol version to use for this message
 * @return FREESPACE_SUCCESS or an error
 */
LIBFREESPACE_API int freespace_decodeFRSWriteResponse(const uint8_t* message, int length, struct freespace_FRSWriteResponse* s, uint8_t ver);

/** @ingroup messages 
 * This is sent from the device to the host to convey an FRS record.
 */
struct freespace_FRSReadResponse {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** Status:
	0: no error
	1: unrecognized FRS type
	2: busy
	3: read completed
	4: offset out of range
	5: record empty
	6: read block completed
	7: read block completed and read reacord completed */
	int status;

	/** Data Length indicates the number of data words contained within the message, typically 5 words */
	int dataLength;

	/** Word Offset indicates the number of words the data is offset from the beginning of the record */
	uint16_t wordOffset;
	uint32_t data[3];

	/** FRS record type */
	uint16_t FRStype;
};


/** @ingroup messages
 * Decode a FRSReadResponse message. Fill out the corresponding values in struct s.
 *
 * @param message the message to decode that was received from the Freespace device
 * @param length the length of the received message
 * @param s the preallocated freespace_FRSReadResponse struct to decode into
 * @param ver the protocol version to use for this message
 * @return FREESPACE_SUCCESS or an error
 */
LIBFREESPACE_API int freespace_decodeFRSReadResponse(const uint8_t* message, int length, struct freespace_FRSReadResponse* s, uint8_t ver);

/** @ingroup messages 
 * This report provides the results of a packet error rate test.  WiCE(tm) only.
 */
struct freespace_PerResponse {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** Frame count of the PER test.  The duration. */
	uint32_t count;

	/** Number of master-to-slave errors detected during the test.  Maximum 1 per frame. */
	uint32_t msError;

	/** Number of slave-to-master errors detected during the test.  Maximum 2 per frame. */
	uint32_t smError;

	/** Number of frame errors detected during the test.  A frame error occurred if both slave-to-master messages in a frame were errors.  Maximum 1 per frame. */
	uint32_t frError;
};


/** @ingroup messages
 * Decode a PerResponse message. Fill out the corresponding values in struct s.
 *
 * @param message the message to decode that was received from the Freespace device
 * @param length the length of the received message
 * @param s the preallocated freespace_PerResponse struct to decode into
 * @param ver the protocol version to use for this message
 * @return FREESPACE_SUCCESS or an error
 */
LIBFREESPACE_API int freespace_decodePerResponse(const uint8_t* message, int length, struct freespace_PerResponse* s, uint8_t ver);

/** @ingroup messages 
 * This is sent from the host towards the device to initiate a flash record write.
	A length of 0 will cause the record to be invalidated.
 */
struct freespace_FRSWriteRequest {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** Length in 32-bit words of record to be written. */
	uint16_t length;

	/** FRS record type to read. */
	uint16_t FRStype;
};


/** @ingroup messages
 * Encode a FRSWriteRequest message.
 *
 * @param s the freespace_FRSWriteRequest struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeFRSWriteRequest(const struct freespace_FRSWriteRequest* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * This message is sent from the host towards the device to write data to the record a previous write request indicated.
 */
struct freespace_FRSWriteData {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** Offset from start of record to write data. */
	uint16_t wordOffset;

	/** 32-bit word to write. */
	uint32_t data;
};


/** @ingroup messages
 * Encode a FRSWriteData message.
 *
 * @param s the freespace_FRSWriteData struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeFRSWriteData(const struct freespace_FRSWriteData* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * Undocumented Message
 */
struct freespace_FRSReadRequest {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** Offset from start of record to begin reading. */
	uint16_t readOffset;

	/** FRS record type to read. */
	uint16_t FRStype;

	/** Number of 32-bit words to read. */
	uint16_t BlockSize;
};


/** @ingroup messages
 * Encode a FRSReadRequest message.
 *
 * @param s the freespace_FRSReadRequest struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodeFRSReadRequest(const struct freespace_FRSReadRequest* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * Configures and executes packet error rate tests.  WiCE(tm) only.
 */
struct freespace_PerRequest {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** 0: sets the frequency set for fixed-frequency PER tests.  1: starts a PER test. */
	uint8_t op;

	/** op == 0: Sets fixed channels for the test.  All 5 0xFF will clear the fixed frequency state.
op == 1: Starts a PER test of duration ((payload[1] * 256 + payload[0]) * 256) WiCE(tm) frames. */
	uint8_t payload[5];
};


/** @ingroup messages
 * Encode a PerRequest message.
 *
 * @param s the freespace_PerRequest struct
 * @param message the string to put the encoded message into
 * @param maxlength the maximum length of the message
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encodePerRequest(const struct freespace_PerRequest* s, uint8_t* message, int maxlength);

/** @ingroup messages 
 * Conveys the handheld device body and user frame motion.
 */
struct freespace_BodyUserFrame {
	uint8_t ver; /**< HID protocol version */
	uint8_t len; /**< Length, used in version 2 only */
	uint8_t dest; /**< Destination, used in version 2 only */
	uint8_t src; /**< Source, used in version 2 only */


	/** Button bits. */
	uint8_t button1;
	uint8_t button2;
	uint8_t button3;
	uint8_t button4;
	uint8_t button5;
	uint8_t button6;
	uint8_t button7;
	uint8_t button8;

	/** X pointer movement. */
	int8_t deltaX;

	/** Y pointer movement. */
	int8_t deltaY;

	/** Scroll wheel movement. */
	int8_t deltaWheel;

	/** Correlates the position report with the Body Frame Motion Report */
	uint16_t sequenceNumber;

	/** Linear Acceleration is reported in SI units (cm/s^2) with an exponent of -1. X is positive forward. Y is positive right. Z is positive down wrt handheld frame of reference. */
	int16_t linearAccelX;
	int16_t linearAccelY;
	int16_t linearAccelZ;

	/** Angular Velocity is reported in units of rad/s with an exponent of -3. X positive is tilt right(roll). Y positive it tilt up(pitch). Z positive is turn right(yaw) wrt the handheld device frame of reference. */
	int16_t angularVelX;
	int16_t angularVelY;
	int16_t angularVelZ;

	/** Linear Offset is in units of meters. X positive is right. Y positive is near. Z positive is down wrt the user frame of reference. */
	int16_t linearPosX;
	int16_t linearPosY;
	int16_t linearPosZ;

	/** Angular Position is in dimensionless units. The axes are given in quaternion form where A, B, C, D represent the real, i, j, and k coefficients. */
	int16_t angularPosB;
	int16_t angularPosC;
	int16_t angularPosD;
	int16_t angularPosA;
};


/** @ingroup messages
 * Decode a BodyUserFrame message. Fill out the corresponding values in struct s.
 *
 * @param message the message to decode that was received from the Freespace device
 * @param length the length of the received message
 * @param s the preallocated freespace_BodyUserFrame struct to decode into
 * @param ver the protocol version to use for this message
 * @return FREESPACE_SUCCESS or an error
 */
LIBFREESPACE_API int freespace_decodeBodyUserFrame(const uint8_t* message, int length, struct freespace_BodyUserFrame* s, uint8_t ver);


/** @ingroup messages
 * An enumeration for all the types of messages that can exist. Used in freespace_message
 * to determine the type of message contained in the union
 */
enum MessageTypes {
    FREESPACE_MESSAGE_COPROCESSOROUTREPORT = 0,
    FREESPACE_MESSAGE_COPROCESSORINREPORT = 1,
    FREESPACE_MESSAGE_PAIRINGMESSAGE = 2,
    FREESPACE_MESSAGE_PRODUCTIDREQUEST = 3,
    FREESPACE_MESSAGE_LEDSETREQUEST = 4,
    FREESPACE_MESSAGE_LINKQUALITYREQUEST = 5,
    FREESPACE_MESSAGE_ALWAYSONREQUEST = 6,
    FREESPACE_MESSAGE_FREQUENCYFIXREQUEST = 7,
    FREESPACE_MESSAGE_SOFTWARERESETMESSAGE = 8,
    FREESPACE_MESSAGE_DONGLERFDISABLEMESSAGE = 9,
    FREESPACE_MESSAGE_TXDISABLEMESSAGE = 10,
    FREESPACE_MESSAGE_DONGLERFSUPRESSHOMEFREQUENCYMESSAGE = 11,
    FREESPACE_MESSAGE_FRSLOOPREADREQUEST = 12,
    FREESPACE_MESSAGE_FRSLOOPWRITEREQUEST = 13,
    FREESPACE_MESSAGE_FRSLOOPWRITEDATA = 14,
    FREESPACE_MESSAGE_FRSDONGLEREADREQUEST = 15,
    FREESPACE_MESSAGE_FRSDONGLEWRITEREQUEST = 16,
    FREESPACE_MESSAGE_FRSDONGLEWRITEDATA = 17,
    FREESPACE_MESSAGE_FRSEFLASHREADREQUEST = 18,
    FREESPACE_MESSAGE_FRSEFLASHWRITEREQUEST = 19,
    FREESPACE_MESSAGE_FRSEFLASHWRITEDATA = 20,
    FREESPACE_MESSAGE_DONGLERFENABLEMESSAGE = 21,
    FREESPACE_MESSAGE_DATAMODEREQUEST = 22,
    FREESPACE_MESSAGE_BUTTONTESTMODEREQUEST = 23,
    FREESPACE_MESSAGE_PAIRINGRESPONSE = 24,
    FREESPACE_MESSAGE_PRODUCTIDRESPONSE = 25,
    FREESPACE_MESSAGE_LINKSTATUS = 26,
    FREESPACE_MESSAGE_ALWAYSONRESPONSE = 27,
    FREESPACE_MESSAGE_FRSLOOPREADRESPONSE = 28,
    FREESPACE_MESSAGE_FRSLOOPWRITERESPONSE = 29,
    FREESPACE_MESSAGE_FRSDONGLEREADRESPONSE = 30,
    FREESPACE_MESSAGE_FRSDONGLEWRITERESPONSE = 31,
    FREESPACE_MESSAGE_FRSEFLASHREADRESPONSE = 32,
    FREESPACE_MESSAGE_FRSEFLASHWRITERESPONSE = 33,
    FREESPACE_MESSAGE_DATAMODERESPONSE = 34,
    FREESPACE_MESSAGE_BUTTONTESTMODERESPONSE = 35,
    FREESPACE_MESSAGE_BATTERYLEVELREQUEST = 36,
    FREESPACE_MESSAGE_BATTERYLEVEL = 37,
    FREESPACE_MESSAGE_BODYFRAME = 38,
    FREESPACE_MESSAGE_USERFRAME = 39,
    FREESPACE_MESSAGE_DATAMOTIONCONTROL = 40,
    FREESPACE_MESSAGE_FRSWRITERESPONSE = 41,
    FREESPACE_MESSAGE_FRSREADRESPONSE = 42,
    FREESPACE_MESSAGE_PERRESPONSE = 43,
    FREESPACE_MESSAGE_FRSWRITEREQUEST = 44,
    FREESPACE_MESSAGE_FRSWRITEDATA = 45,
    FREESPACE_MESSAGE_FRSREADREQUEST = 46,
    FREESPACE_MESSAGE_PERREQUEST = 47,
    FREESPACE_MESSAGE_BODYUSERFRAME = 48,
};

/** @ingroup messages
 * freespace_message has an enum which defines the type of the message contained
 * and a union of all the possible message structs. 
 */
struct freespace_message {
    int messageType;
    union {
		struct freespace_CoprocessorOutReport coprocessorOutReport;
		struct freespace_CoprocessorInReport coprocessorInReport;
		struct freespace_PairingMessage pairingMessage;
		struct freespace_ProductIDRequest productIDRequest;
		struct freespace_LEDSetRequest lEDSetRequest;
		struct freespace_LinkQualityRequest linkQualityRequest;
		struct freespace_AlwaysOnRequest alwaysOnRequest;
		struct freespace_FrequencyFixRequest frequencyFixRequest;
		struct freespace_SoftwareResetMessage softwareResetMessage;
		struct freespace_DongleRFDisableMessage dongleRFDisableMessage;
		struct freespace_TxDisableMessage txDisableMessage;
		struct freespace_DongleRFSupressHomeFrequencyMessage dongleRFSupressHomeFrequencyMessage;
		struct freespace_FRSLoopReadRequest fRSLoopReadRequest;
		struct freespace_FRSLoopWriteRequest fRSLoopWriteRequest;
		struct freespace_FRSLoopWriteData fRSLoopWriteData;
		struct freespace_FRSDongleReadRequest fRSDongleReadRequest;
		struct freespace_FRSDongleWriteRequest fRSDongleWriteRequest;
		struct freespace_FRSDongleWriteData fRSDongleWriteData;
		struct freespace_FRSEFlashReadRequest fRSEFlashReadRequest;
		struct freespace_FRSEFlashWriteRequest fRSEFlashWriteRequest;
		struct freespace_FRSEFlashWriteData fRSEFlashWriteData;
		struct freespace_DongleRFEnableMessage dongleRFEnableMessage;
		struct freespace_DataModeRequest dataModeRequest;
		struct freespace_ButtonTestModeRequest buttonTestModeRequest;
		struct freespace_PairingResponse pairingResponse;
		struct freespace_ProductIDResponse productIDResponse;
		struct freespace_LinkStatus linkStatus;
		struct freespace_AlwaysOnResponse alwaysOnResponse;
		struct freespace_FRSLoopReadResponse fRSLoopReadResponse;
		struct freespace_FRSLoopWriteResponse fRSLoopWriteResponse;
		struct freespace_FRSDongleReadResponse fRSDongleReadResponse;
		struct freespace_FRSDongleWriteResponse fRSDongleWriteResponse;
		struct freespace_FRSEFlashReadResponse fRSEFlashReadResponse;
		struct freespace_FRSEFlashWriteResponse fRSEFlashWriteResponse;
		struct freespace_DataModeResponse dataModeResponse;
		struct freespace_ButtonTestModeResponse buttonTestModeResponse;
		struct freespace_BatteryLevelRequest batteryLevelRequest;
		struct freespace_BatteryLevel batteryLevel;
		struct freespace_BodyFrame bodyFrame;
		struct freespace_UserFrame userFrame;
		struct freespace_DataMotionControl dataMotionControl;
		struct freespace_FRSWriteResponse fRSWriteResponse;
		struct freespace_FRSReadResponse fRSReadResponse;
		struct freespace_PerResponse perResponse;
		struct freespace_FRSWriteRequest fRSWriteRequest;
		struct freespace_FRSWriteData fRSWriteData;
		struct freespace_FRSReadRequest fRSReadRequest;
		struct freespace_PerRequest perRequest;
		struct freespace_BodyUserFrame bodyUserFrame;
    };
};

/** @ingroup messages
 * Decode an arbitrary message. Fill out the corresponding values in struct s.
 *
 * @param message the message to decode that was received from the Freespace device
 * @param length the length of the received message
 * @param s the preallocated freespace_message struct to decode into
 * @param ver the HID protocol version to use to decode the message
 * @return FREESPACE_SUCESS or an error code
 */
LIBFREESPACE_API int freespace_decode_message(const uint8_t* message, int length, struct freespace_message* s, uint8_t ver);

/** @ingroup messages
 * Encode an arbitrary message.
 *
 * @param hVer the HID protocol version to use to encode the message
 * @param message the freespace_message struct
 * @param msgBuf the buffer to put the encoded message into
 * @param maxLength the maximum length of the encoded message (i.e sizeof(*msgBuf))
 * @param dest the HCOMM destination address to send the message to
 * @return the actual size of the encoded message or an error code
 */
LIBFREESPACE_API int freespace_encode_message(const uint8_t hVer, struct freespace_message* message, uint8_t* msgBuf, int maxLength, uint8_t dest);

#ifdef __cplusplus
}
#endif

#endif /* FREESPACE_CODECS_H_ */
