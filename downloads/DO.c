/* Master 0, Slave 0, "REMA-P5-DIGITAL-OUTPUT"
 * Vendor ID:       0xe00004d8
 * Product code:    0x00000021
 * Revision number: 0x00000001
 */

 ec_pdo_entry_info_t slave_0_pdo_entries[] = {
    {0x3101, 0x01, 8}, /* Output */
    {0x3101, 0x02, 8}, /* Output */
};

ec_pdo_info_t slave_0_pdos[] = {
    {0x1a00, 1, slave_0_pdo_entries + 0}, /* Byte 0 */
    {0x1a01, 1, slave_0_pdo_entries + 1}, /* Byte 0 */
};

ec_sync_info_t slave_0_syncs[] = {
    {0, EC_DIR_OUTPUT, 2, slave_0_pdos + 0, EC_WD_ENABLE},
    {1, EC_DIR_OUTPUT, 0, NULL, EC_WD_ENABLE},
    {0xff}
};