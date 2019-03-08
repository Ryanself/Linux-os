__INLINE u32 ipc_app2emb_trigger_get(void *env);
__INLINE void ipc_app2emb_trigger_set(void *env, u32 value);
__INLINE u16 ipc_app2emb_trigger_getf(void *env);
__INLINE void ipc_app2emb_trigger_setf(void *env, u16 app2embtrigger);
__INLINE u32 ipc_emb2app_rawstatus_get(void *env);
__INLINE void ipc_emb2app_rawstatus_set(void *env, u32 value);
__INLINE u8 ipc_emb2app_rawstatus_getf(void *env);
__INLINE u32 ipc_emb2app_ack_get(void *env);
__INLINE void ipc_emb2app_ack_clear(void *env, u32 value);
__INLINE u8 ipc_emb2app_ack_getf(void *env);
__INLINE void ipc_emb2app_ack_clearf(void *env, u8 emb2appack);
__INLINE u32 ipc_emb2app_unmask_get(void *env);
__INLINE void ipc_emb2app_unmask_set(void *env, u32 value);
__INLINE u8 ipc_emb2app_unmask_getf(void *env);
__INLINE void ipc_emb2app_unmask_setf(void *env, u8 emb2appunmask);
__INLINE u32 ipc_emb2app_unmask_clear_get(void *env);
__INLINE void ipc_emb2app_unmask_clear(void *env, u32 value);
__INLINE void ipc_emb2app_unmask_clearf(void *env, u8 emb2appunmask);
__INLINE u32 ipc_emb2app_status_get(void *env);
__INLINE void ipc_emb2app_status_set(void *env, u32 value);
__INLINE u8 ipc_emb2app_status_getf(void *env);
__INLINE u32 ipc_app_buserr_cause_get(void *env);
__INLINE void ipc_app_buserr_cause_clear(void *env, u32 value);
__INLINE void ipc_app_buserr_cause_pack(void *env, u8 write, u8 size, u32 address);
__INLINE void ipc_app_buserr_cause_unpack(void *env, u8* write, u8* size, u32* address);
__INLINE u8 ipc_write_getf(void *env);
__INLINE void ipc_write_clearf(void *env, u8 write);
__INLINE u8 ipc_size_getf(void *env);
__INLINE void ipc_size_clearf(void *env, u8 size);
__INLINE u32 ipc_address_getf(void *env);
__INLINE void ipc_address_clearf(void *env, u32 address);
