/**
 ****************************************************************************************
 *
 * @file rwnx_ipc_app.h
 *
 * @brief IPC module register definitions
 *
 * Copyright (C) RivieraWaves 2011-2014
 *
 ****************************************************************************************
 */

#ifndef _REG_IPC_APP_H_
#define _REG_IPC_APP_H_

#include "co_int.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"


//TODO
#define IPC_REG_BASE_ADDR                (0xB10C0000)
/* Macros for IPC registers access */
#define REG_IPC_APP_RD(env, INDEX) ( *(volatile u32*)( IPC_REG_BASE_ADDR + 4*(INDEX) ))

#define REG_IPC_APP_WR(env, INDEX, value) ( (*(volatile uint32_t *)(IPC_REG_BASE_ADDR + 4*(INDEX))) = (value) )


#define REG_IPC_APP_DECODING_MASK 0x000007FF

/**
 * @brief APP2EMB_TRIGGER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  15:00      APP2EMB_TRIGGER   0x0
 * </pre>
 */
#define IPC_APP2EMB_TRIGGER_ADDR   (WIFI_REG_IPC_EMB_BASE_ADDR + 0x0)
#define IPC_APP2EMB_TRIGGER_OFFSET 0x00000000
#define IPC_APP2EMB_TRIGGER_INDEX  0x00000000
#define IPC_APP2EMB_TRIGGER_RESET  0x00000000

u32 ipc_app2emb_trigger_get(void *env)
{
	return REG_IPC_APP_RD(env, IPC_APP2EMB_TRIGGER_INDEX);
}

void ipc_app2emb_trigger_set(void *env, u32 value)
{
	REG_IPC_APP_WR(env, IPC_APP2EMB_TRIGGER_INDEX, value);
}

// field definitions
#define IPC_APP2EMB_TRIGGER_MASK   ((u32)0xFFFFFFFF)
#define IPC_APP2EMB_TRIGGER_LSB    0
#define IPC_APP2EMB_TRIGGER_WIDTH  ((u32)0x00000020)

#define IPC_APP2EMB_TRIGGER_RST    0x0

u16 ipc_app2emb_trigger_getf(void *env)
{
	u32 localVal = REG_IPC_APP_RD(env, IPC_APP2EMB_TRIGGER_INDEX);
	ASSERT_ERR((localVal & ~((u32)0x0000FFFF)) == 0);
	return (localVal >> 0);
}

void ipc_app2emb_trigger_setf(void *env, u16 app2embtrigger)
{
	ASSERT_ERR((((u32)app2embtrigger << 0) & ~((u32)0x0000FFFF)) == 0);
	REG_IPC_APP_WR(env, IPC_APP2EMB_TRIGGER_INDEX, (u32)app2embtrigger << 0);
}

/**
 * @brief EMB2APP_RAWSTATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00    EMB2APP_RAWSTATUS   0x0
 * </pre>
 */
#define IPC_EMB2APP_RAWSTATUS_ADDR   (WIFI_REG_IPC_EMB_BASE_ADDR + 0x00000004)
#define IPC_EMB2APP_RAWSTATUS_OFFSET 0x00000004
#define IPC_EMB2APP_RAWSTATUS_INDEX  0x00000001
#define IPC_EMB2APP_RAWSTATUS_RESET  0x00000000

u32 ipc_emb2app_rawstatus_get(void *env)
{
	return REG_IPC_APP_RD(env, IPC_EMB2APP_RAWSTATUS_INDEX);
}

void ipc_emb2app_rawstatus_set(void *env, u32 value)
{
	REG_IPC_APP_WR(env, IPC_EMB2APP_RAWSTATUS_INDEX, value);
}

// field definitions
#define IPC_EMB2APP_RAWSTATUS_MASK   ((u32)0x000000FF)
#define IPC_EMB2APP_RAWSTATUS_LSB    0
#define IPC_EMB2APP_RAWSTATUS_WIDTH  ((u32)0x00000008)

#define IPC_EMB2APP_RAWSTATUS_RST    0x0

u8 ipc_emb2app_rawstatus_getf(void *env)
{
	u32 localVal = REG_IPC_APP_RD(env, IPC_EMB2APP_RAWSTATUS_INDEX);
	ASSERT_ERR((localVal & ~((u32)0x000000FF)) == 0);
	return (localVal >> 0);
}

/**
 * @brief EMB2APP_ACK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00          EMB2APP_ACK   0x0
 * </pre>
 */
#define IPC_EMB2APP_ACK_ADDR   (WIFI_REG_IPC_EMB_BASE_ADDR + 0x00000008)
#define IPC_EMB2APP_ACK_OFFSET 0x00000008
#define IPC_EMB2APP_ACK_INDEX  0x00000002
#define IPC_EMB2APP_ACK_RESET  0x00000000

u32 ipc_emb2app_ack_get(void *env)
{
	return REG_IPC_APP_RD(env, IPC_EMB2APP_ACK_INDEX);
}

void ipc_emb2app_ack_clear(void *env, u32 value)
{
	REG_IPC_APP_WR(env, IPC_EMB2APP_ACK_INDEX, value);
}

// field definitions
#define IPC_EMB2APP_ACK_MASK   ((u32)0x000000FF)
#define IPC_EMB2APP_ACK_LSB    0
#define IPC_EMB2APP_ACK_WIDTH  ((u32)0x00000008)

#define IPC_EMB2APP_ACK_RST    0x0

u8 ipc_emb2app_ack_getf(void *env)
{
	u32 localVal = REG_IPC_APP_RD(env, IPC_EMB2APP_ACK_INDEX);
	ASSERT_ERR((localVal & ~((u32)0x000000FF)) == 0);
	return (localVal >> 0);
}

void ipc_emb2app_ack_clearf(void *env, u8 emb2appack)
{
	ASSERT_ERR((((u32)emb2appack << 0) & ~((u32)0x000000FF)) == 0);
	REG_IPC_APP_WR(env, IPC_EMB2APP_ACK_INDEX, (u32)emb2appack << 0);
}

/**
 * @brief EMB2APP_UNMASK_SET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00       EMB2APP_UNMASK   0x0
 * </pre>
 */
#define IPC_EMB2APP_UNMASK_SET_ADDR   (WIFI_REG_IPC_EMB_BASE_ADDR + 0x0000000C)
#define IPC_EMB2APP_UNMASK_SET_OFFSET 0x0000000C
#define IPC_EMB2APP_UNMASK_SET_INDEX  0x00000003
#define IPC_EMB2APP_UNMASK_SET_RESET  0x00000000

u32 ipc_emb2app_unmask_get(void *env)
{
	return REG_IPC_APP_RD(env, IPC_EMB2APP_UNMASK_SET_INDEX);
}

void ipc_emb2app_unmask_set(void *env, u32 value)
{
	REG_IPC_APP_WR(env, IPC_EMB2APP_UNMASK_SET_INDEX, value);
}

// field definitions
#define IPC_EMB2APP_UNMASK_MASK   ((u32)0x000000FF)
#define IPC_EMB2APP_UNMASK_LSB    0
#define IPC_EMB2APP_UNMASK_WIDTH  ((u32)0x00000008)

#define IPC_EMB2APP_UNMASK_RST    0x0

u8 ipc_emb2app_unmask_getf(void *env)
{
	u32 localVal = REG_IPC_APP_RD(env, IPC_EMB2APP_UNMASK_SET_INDEX);
	ASSERT_ERR((localVal & ~((u32)0x000000FF)) == 0);
	return (localVal >> 0);
}

void ipc_emb2app_unmask_setf(void *env, u8 emb2appunmask)
{
	ASSERT_ERR((((u32)emb2appunmask << 0) & ~((u32)0x000000FF)) == 0);
	REG_IPC_APP_WR(env, IPC_EMB2APP_UNMASK_SET_INDEX, (u32)emb2appunmask << 0);
}

/**
 * @brief EMB2APP_UNMASK_CLEAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00       EMB2APP_UNMASK   0x0
 * </pre>
 */
#define IPC_EMB2APP_UNMASK_CLEAR_ADDR   (WIFI_REG_IPC_EMB_BASE_ADDR + 0x00000010)
#define IPC_EMB2APP_UNMASK_CLEAR_OFFSET 0x00000010
#define IPC_EMB2APP_UNMASK_CLEAR_INDEX  0x00000004
#define IPC_EMB2APP_UNMASK_CLEAR_RESET  0x00000000

u32 ipc_emb2app_unmask_clear_get(void *env)
{
	return REG_IPC_APP_RD(env, IPC_EMB2APP_UNMASK_CLEAR_INDEX);
}

void ipc_emb2app_unmask_clear(void *env, u32 value)
{
	REG_IPC_APP_WR(env, IPC_EMB2APP_UNMASK_CLEAR_INDEX, value);
}

// fields defined in symmetrical set/clear register
void ipc_emb2app_unmask_clearf(void *env, u8 emb2appunmask)
{
	ASSERT_ERR((((u32)emb2appunmask << 0) & ~((u32)0x000000FF)) == 0);
	REG_IPC_APP_WR(env, IPC_EMB2APP_UNMASK_CLEAR_INDEX, (u32)emb2appunmask << 0);
}

/**
 * @brief EMB2APP_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00       EMB2APP_STATUS   0x0
 * </pre>
 */
#define IPC_EMB2APP_STATUS_ADDR   (WIFI_REG_IPC_EMB_BASE_ADDR + 0x0000001C)
#define IPC_EMB2APP_STATUS_OFFSET 0x0000001C
#define IPC_EMB2APP_STATUS_INDEX  0x00000007
#define IPC_EMB2APP_STATUS_RESET  0x00000000

u32 ipc_emb2app_status_get(void *env)
{
	return REG_IPC_APP_RD(env, IPC_EMB2APP_STATUS_INDEX);
}

void ipc_emb2app_status_set(void *env, u32 value)
{
	REG_IPC_APP_WR(env, IPC_EMB2APP_STATUS_INDEX, value);
}

// field definitions
#define IPC_EMB2APP_STATUS_MASK   ((u32)0x000000FF)
#define IPC_EMB2APP_STATUS_LSB    0
#define IPC_EMB2APP_STATUS_WIDTH  ((u32)0x00000008)

#define IPC_EMB2APP_STATUS_RST    0x0

u8 ipc_emb2app_status_getf(void *env)
{
	u32 localVal = REG_IPC_APP_RD(env, IPC_EMB2APP_STATUS_INDEX);
	ASSERT_ERR((localVal & ~((u32)0x000000FF)) == 0);
	return (localVal >> 0);
}

/**
 * @brief APP_BUSERR_CAUSE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     28                WRITE   0
 *  27:26                 SIZE   0x0
 *  25:00              ADDRESS   0x0
 * </pre>
 */
#define IPC_APP_BUSERR_CAUSE_ADDR   (WIFI_REG_IPC_EMB_BASE_ADDR + 0x00000040)
#define IPC_APP_BUSERR_CAUSE_OFFSET 0x00000040
#define IPC_APP_BUSERR_CAUSE_INDEX  0x00000040
#define IPC_APP_BUSERR_CAUSE_RESET  0x49504332

u32 ipc_app_buserr_cause_get(void *env)
{
	return REG_IPC_APP_RD(env, IPC_APP_BUSERR_CAUSE_INDEX);
}

void ipc_app_buserr_cause_clear(void *env, u32 value)
{
	REG_IPC_APP_WR(env, IPC_APP_BUSERR_CAUSE_INDEX, value);
}

// field definitions
#define IPC_WRITE_BIT      ((u32)0x10000000)
#define IPC_WRITE_POS      28
#define IPC_SIZE_MASK      ((u32)0x0C000000)
#define IPC_SIZE_LSB       26
#define IPC_SIZE_WIDTH     ((u32)0x00000002)
#define IPC_ADDRESS_MASK   ((u32)0x03FFFFFF)
#define IPC_ADDRESS_LSB    0
#define IPC_ADDRESS_WIDTH  ((u32)0x0000001A)

#define IPC_WRITE_RST      0x0
#define IPC_SIZE_RST       0x0
#define IPC_ADDRESS_RST    0x0

void ipc_app_buserr_cause_pack(void *env, u8 write, u8 size, u32 address)
{
	ASSERT_ERR((((u32)write << 28) & ~((u32)0x10000000)) == 0);
	ASSERT_ERR((((u32)size << 26) & ~((u32)0x0C000000)) == 0);
	ASSERT_ERR((((u32)address << 0) & ~((u32)0x03FFFFFF)) == 0);
	REG_IPC_APP_WR(env, IPC_APP_BUSERR_CAUSE_INDEX,  ((u32)write << 28) | ((u32)size << 26) | ((u32)address << 0));
}

void ipc_app_buserr_cause_unpack(void *env, u8* write, u8* size, u32* address)
{
	u32 localVal = REG_IPC_APP_RD(env, IPC_APP_BUSERR_CAUSE_INDEX);

	*write = (localVal & ((u32)0x10000000)) >> 28;
	*size = (localVal & ((u32)0x0C000000)) >> 26;
	*address = (localVal & ((u32)0x03FFFFFF)) >> 0;
}

u8 ipc_write_getf(void *env)
{
	u32 localVal = REG_IPC_APP_RD(env, IPC_APP_BUSERR_CAUSE_INDEX);
	return ((localVal & ((u32)0x10000000)) >> 28);
}

void ipc_write_clearf(void *env, u8 write)
{
	ASSERT_ERR((((u32)write << 28) & ~((u32)0x10000000)) == 0);
	REG_IPC_APP_WR(env, IPC_APP_BUSERR_CAUSE_INDEX, (u32)write << 28);
}

u8 ipc_size_getf(void *env)
{
	u32 localVal = REG_IPC_APP_RD(env, IPC_APP_BUSERR_CAUSE_INDEX);
	return ((localVal & ((u32)0x0C000000)) >> 26);
}

void ipc_size_clearf(void *env, u8 size)
{
	ASSERT_ERR((((u32)size << 26) & ~((u32)0x0C000000)) == 0);
	REG_IPC_APP_WR(env, IPC_APP_BUSERR_CAUSE_INDEX, (u32)size << 26);
}

u32 ipc_address_getf(void *env)
{
	u32 localVal = REG_IPC_APP_RD(env, IPC_APP_BUSERR_CAUSE_INDEX);
	return ((localVal & ((u32)0x03FFFFFF)) >> 0);
}

void ipc_address_clearf(void *env, u32 address)
{
	ASSERT_ERR((((u32)address << 0) & ~((u32)0x03FFFFFF)) == 0);
	REG_IPC_APP_WR(env, IPC_APP_BUSERR_CAUSE_INDEX, (u32)address << 0);
}


#endif // _REG_IPC_APP_H_
