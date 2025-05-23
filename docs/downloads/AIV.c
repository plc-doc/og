/* Master 0, Slave 0, "SA-P5-AIV"
 * Vendor ID:       0x00000001
 * Product code:    0x01009252
 * Revision number: 0x00000001
 */

 ec_pdo_entry_info_t slave_0_pdo_entries[] = {
    {0x6000, 0x01, 32}, /* Channel 1 */
    {0x6000, 0x02, 32}, /* Channel 2 */
    {0x6000, 0x03, 32}, /* Channel 3 */
    {0x6000, 0x04, 32}, /* Channel 4 */
    {0x6000, 0x05, 32}, /* Channel 5 */
    {0x6000, 0x06, 32}, /* Channel 6 */
    {0x6000, 0x07, 32}, /* Channel 7 */
    {0x6000, 0x08, 32}, /* Channel 8 */
};

ec_pdo_info_t slave_0_pdos[] = {
    {0x1a00, 8, slave_0_pdo_entries + 0}, /* Current inputs (PDO) */
};

ec_sync_info_t slave_0_syncs[] = {
    {0, EC_DIR_OUTPUT, 0, NULL, EC_WD_DISABLE},
    {1, EC_DIR_INPUT, 0, NULL, EC_WD_DISABLE},
    {2, EC_DIR_OUTPUT, 0, NULL, EC_WD_DISABLE},
    {3, EC_DIR_INPUT, 1, slave_0_pdos + 0, EC_WD_DISABLE},
    {0xff}
};