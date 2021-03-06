#ifndef __NEU_TEE_CLIENT_API_H_
#define __NEU_TEE_CLIENT_API_H_

#define TEEC_CLIENT_API_VERSION 1

#define MAX_SESSIONS_PER_DEVICE 16
#define MAX_OPERATIONS_PER_SESSION 16
#define MAX_MEMBLOCKS_PER_SESSION 16
#define MAX_MEMBLOCKS_PER_OPERATION 4

/* #define DEBUG */

#define TEEC_CONFIG_SHAREDMEM_MAX_SIZE 0x80000

#include <linux/list.h>

enum TEEIC_Result {
	TEEC_SUCCESS = 0x0,
	TEEIC_SUCCESS = 0x0,
	TEEC_ERROR_INTERNAL = 0x00000001,
	TEEC_ERROR_RESOURCE_LIMIT = 0x00000002,
	TEEC_ERROR_DEVICE_BUSY = 0x00000003,
	TEEC_ERROR_DEVICE_HANDLE_INVALID = 0x00000004,
	TEEC_ERROR_DEVICE_OVERFLOW = 0x00000005,
	TEEC_ERROR_DEVICE_EVENT_INVALID = 0x00000006,
	TEEC_ERROR_TA_NOT_EXIST = 0x00000009,
	TEEC_ERROR_HOST_NAME_EXIST = 0x0000000a,
	TEEC_ERROR_HOST_NOT_EXIST = 0x0000000b,
	TEEC_ERROR_GATE_NOT_EXIST = 0x0000000c,
	TEEC_ERROR_PIPE_CREATE_DENIED = 0x0000000d,
	TEEC_ERROR_PIPE_BUSY = 0x0000000e,
	TEEC_ERROR_NETWORK_ERROR = 0x00000010,
	TEEC_ERROR_CIPHERTEXT_ERROR = 0x00000011,
	TEEC_ERROR_UNIQUE_CONFLICT = 0x00000012,
	TEEC_ERROR_GENERIC = 0xFFFF0000,
	TEEIC_ERROR_GENERIC = 0xFFFF0000,
	TEEC_ERROR_ACCESS_DENIED = 0xFFFF0001,
	TEEIC_ERROR_ACCESS_DENIED = 0xFFFF0001,
	TEEC_ERROR_CANCEL = 0xFFFF0002,
	TEEIC_ERROR_CANCEL = 0xFFFF0002,
	TEEC_ERROR_ACCESS_CONFLICT = 0xFFFF0003,
	TEEIC_ERROR_ACCESS_CONFLICT = 0xFFFF0003,
	TEEC_ERROR_EXCESS_DATA = 0xFFFF0004,
	TEEIC_ERROR_EXCESS_DATA = 0xFFFF0004,
	TEEC_ERROR_BAD_FORMAT = 0xFFFF0005,
	TEEIC_ERROR_BAD_FORMAT = 0xFFFF0005,
	TEEC_ERROR_BAD_PARAMETERS = 0xFFFF0006,
	TEEIC_ERROR_BAD_PARAMETERS = 0xFFFF0006,
	TEEC_ERROR_BAD_STATE = 0xFFFF0007,
	TEEIC_ERROR_BAD_STATE = 0xFFFF0007,
	TEEC_ERROR_ITEM_NOT_FOUND = 0xFFFF0008,
	TEEIC_ERROR_ITEM_NOT_FOUND = 0xFFFF0008,
	TEEC_ERROR_NOT_IMPLEMENTED = 0xFFFF0009,
	TEEIC_ERROR_NOT_IMPLEMENTED = 0xFFFF0009,
	TEEC_ERROR_NOT_SUPPORTED = 0xFFFF000A,
	TEEIC_ERROR_NOT_SUPPORTED = 0xFFFF000A,
	TEEC_ERROR_NO_DATA = 0xFFFF000B,
	TEEIC_ERROR_NO_DATA = 0xFFFF000B,
	TEEC_ERROR_OUT_OF_MEMORY = 0xFFFF000C,
	TEEIC_ERROR_OUT_OF_MEMORY = 0xFFFF000C,
	TEEC_ERROR_BUSY = 0xFFFF000D,
	TEEIC_ERROR_BUSY = 0xFFFF000D,
	TEEC_ERROR_COMMUNICATION = 0xFFFF000E,
	TEEIC_ERROR_COMMUNICATION = 0xFFFF000E,
	TEEC_ERROR_SECURITY = 0xFFFF000F,
	TEEIC_ERROR_SECURITY = 0xFFFF000F,
	TEEC_ERROR_SHORT_BUFFER = 0xFFFF0010,
	TEEIC_ERROR_SHORT_BUFFER = 0xFFFF0010,
	TEEC_ERROR_MAC_INVALID = 0xFFFF3071,
	TEEIC_ERROR_MAC_INVALID = 0xFFFF3071,

	TEEC_ERROR_VNET_INVALID = 0xFFFF6000,
	TEEIC_ERROR_VNET_INVALID = 0xFFFF6000,
	TEEC_ERROR_REEAGENT_INVALID = 0xFFFF6001,
	TEEIC_ERROR_REEAGENT_INVALID = 0xFFFF6001,

	TEEIC_UNDEFINED_ERROR = 0xFFFF7001,
	TEEC_UNDEFINED_ERROR = 0xFFFF7001,

};


#define TEEC_PARAM_TYPES(param0Type, param1Type, param2Type, param3Type) \
	(param3Type << 12 | param2Type << 8 | param1Type << 4 | param0Type)

#define TEEC_VALUE_UNDEF 0xffffffff

#ifdef __cplusplus
extern "C"{
#endif

#define LIST_POISON_PREV    0xDEADBEEF
#define LIST_POISON_NEXT    0xFADEBABE

#ifndef TEEC_RETURN_CODE
#define TEEC_RETURN_CODE
enum TEEC_return_code_origin {
	TEEC_ORIGIN_API = 0x1,
	TEEIC_ORIGIN_API = 0x1,
	TEEC_ORIGIN_COMMS = 0x2,
	TEEIC_ORIGIN_COMMS = 0x2,
	TEEC_ORIGIN_TEE = 0x3,
	TEEIC_ORIGIN_TEE = 0x3,
	TEEC_ORIGIN_TRUSTED_APP = 0x4,
	TEEIC_ORIGIN_TRUSTED_APP = 0x4,

	TEEC_ORIGIN_TEEI = 0x5,
	TEEIC_ORIGIN_TEEI = 0x5,

	TEEC_ORIGIN_ANY_NOT_TRUSTED_APP = 0x10,
	TEEIC_ORIGIN_ANY_NOT_TRUSTED_APP = 0x10,
};
#endif

enum TEEC_login_flags {
	TEEC_LOGIN_PUBLIC = 0x0,
	TEEIC_LOGIN_PUBLIC = 0x0,
	TEEC_LOGIN_USER = 0x1,
	TEEIC_LOGIN_USER = 0x1,
	TEEC_LOGIN_GROUP = 0x2,
	TEEIC_LOGIN_GROUP = 0x2,
	TEEC_LOGIN_APPLICATION = 0x4,
	TEEIC_LOGIN_APPLICATION = 0x4,
	TEEC_LOGIN_USER_APPLICATION = 0x5,
	TEEIC_LOGIN_USER_APPLICATION = 0x5,
	TEEC_LOGIN_GROUP_APPLICATION = 0x6,
	TEEIC_LOGIN_GROUP_APPLICATION = 0x6,
};

enum TEEC_shared_mem_flags {
	TEEC_MEM_INPUT = 0x1,
	TEEIC_MEM_INPUT = 0x1,
	TEEC_MEM_OUTPUT = 0x2,
	TEEIC_MEM_OUTPUT = 0x2,
};

enum TEEC_param_type {
	TEEC_NONE = 0x0,
	TEEIC_NONE = 0x0,
	TEEC_VALUE_INPUT = 0x1,
	TEEIC_VALUE_INPUT = 0x1,
	TEEC_VALUE_OUTPUT = 0x2,
	TEEIC_VALUE_OUTPUT = 0x2,
	TEEC_VALUE_INOUT = 0x3,
	TEEIC_VALUE_INOUT = 0x3,
	TEEC_MEMREF_TEMP_INPUT = 0x5,
	TEEIC_MEMREF_TEMP_INPUT = 0x5,
	TEEC_MEMREF_TEMP_OUTPUT = 0x6,
	TEEIC_MEMREF_TEMP_OUTPUT = 0x6,
	TEEC_MEMREF_TEMP_INOUT = 0x7,
	TEEIC_MEMREF_TEMP_INOUT = 0x7,
	TEEC_MEMREF_WHOLE = 0xc,
	TEEIC_MEMREF_WHOLE = 0xc,

	TEEC_MEMREF_PARTIAL_INPUT = 0xd,
	TEEIC_MEMREF_PARTIAL_INPUT = 0xd,

	TEEC_MEMREF_PARTIAL_OUTPUT = 0xe,
	TEEIC_MEMREF_PARTIAL_OUTPUT = 0xe,

	TEEC_MEMREF_PARTIAL_INOUT = 0xf,
	TEEIC_MEMREF_PARTIAL_INOUT = 0xf,
};

struct UT_TEEC_Context {
	unsigned int fd;				/* Device identifier */
	struct list_head session_list;		/* Sessions list of the device */
	struct list_head shared_mem_list;	/* Shared memory list */
	int s_errno;				/* Error number from the client driver */
	char tee_name[255];			/* host name */

};

struct TEEC_Context {
	struct UT_TEEC_Context *imp;
};

/*
 * @brief Universally Unique IDentifier (UUID) type as defined in
 * [RFC4122].A
 *
 * UUID is the mechanism by which a service is identified.
 */
struct TEEC_UUID {
	unsigned int timeLow;
	unsigned short int timeMid;
	unsigned short int timeHiAndVersion;
	unsigned char clockSeqAndNode[8];
};

/**
* @brief The TEEC_Session structure is used to contain control information
* related to a session between a client and a service.
*
*/
struct UT_TEEC_Session {
	int session_id;
	struct UT_TEEC_Context *device;
	int s_errno;
	struct list_head head;
};

struct TEEC_Session {
	struct UT_TEEC_Session *imp;
};

struct UT_TEEC_SharedMemory {
	struct UT_TEEC_Context *context;
	unsigned int allocated;
	struct list_head head_ref;
	int s_errno;
	void *buffer;
	void *saved_buffer;
	unsigned int size;
};

struct TEEC_SharedMemory {
	void *buffer;
	unsigned int size;
	unsigned int flags;
	struct UT_TEEC_SharedMemory *imp;
};

struct TEEC_Value {
	unsigned int a;
	unsigned int b;
};


struct TEEC_TempMemoryReference {
	void *buffer;
	unsigned int size;
};

struct TEEC_RegisteredMemoryReference {
	struct TEEC_SharedMemory *parent;
	unsigned int size;
	unsigned int offset;
};

union TEEC_Parameter {
	struct TEEC_TempMemoryReference tmpref;
	struct TEEC_RegisteredMemoryReference memref;
	struct TEEC_Value value;
};

struct TEEC_Operation {
	unsigned int started;
	unsigned int paramTypes;
	union TEEC_Parameter params[4];
};

enum shared_mem_flags {
	MEM_SERVICE_RO = 0x0,
	MEM_SERVICE_WO,
	MEM_SERVICE_RW,
	MEM_SERVICE_UNDEFINED
};

unsigned int TEEC_InitializeContext(const char *name, struct TEEC_Context *context);
void TEEC_FinalizeContext(struct TEEC_Context *context);
unsigned int TEEC_RegisterSharedMemory(struct TEEC_Context *context, struct TEEC_SharedMemory *sharedMem);
unsigned int TEEC_AllocateSharedMemory(struct TEEC_Context *context, struct TEEC_SharedMemory *sharedMem);
void TEEC_ReleaseSharedMemory(struct TEEC_SharedMemory *sharedMem);

unsigned int TEEC_OpenSession(struct TEEC_Context *context, struct TEEC_Session *session,
					const struct TEEC_UUID *destination, unsigned int connectionMethod,
					const void *connectionData, struct TEEC_Operation *operation,
					unsigned int *returnOrigin);

void TEEC_CloseSession(struct TEEC_Session *session);

unsigned int TEEC_InvokeCommand(struct TEEC_Session *session,
								unsigned int commandID,
								struct TEEC_Operation *operation,
								unsigned int *returnOrigin);

void TEEC_RequestCancellation(struct TEEC_Operation *operation);

void allow(struct TEEC_Operation *operation);
void block(struct TEEC_Operation *operation);

#ifdef __cplusplus
}
#endif

#endif

