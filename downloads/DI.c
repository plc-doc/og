/* Master 0, Slave 0, "REMA-P5-DIGITAL-INPUT"
 * Vendor ID:       0xe00004d8
 * Product code:    0x00000020
 * Revision number: 0x00000001
 */

 ec_pdo_entry_info_t slave_0_pdo_entries[] = {
    {0x6000, 0x01, 8}, /* Input */
    {0x6080, 0x01, 8}, /* Input */
};

ec_pdo_info_t slave_0_pdos[] = {
    {0x1a00, 1, slave_0_pdo_entries + 0}, /* Byte_Lo */
    {0x1a08, 1, slave_0_pdo_entries + 1}, /* Byte_Hi */
};

ec_sync_info_t slave_0_syncs[] = {
    {0, EC_DIR_INPUT, 2, slave_0_pdos + 0, EC_WD_DISABLE},
    {0xff}
};