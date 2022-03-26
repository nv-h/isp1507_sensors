#ifndef BT_APP_H_
#define BT_APP_H_

#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/conn.h>
#include <bluetooth/uuid.h>
#include <bluetooth/gatt.h>

#define DEVICE_NAME     CONFIG_BT_DEVICE_NAME
#define DEVICE_NAME_LEN (sizeof(DEVICE_NAME) - 1)
// random number
#define BT_UUID_BASE_VAL    BT_UUID_128_ENCODE(0xc7839aa8, 0x1903, 0x40b5, 0xa8f0, 0x426e09ffb390)
#define BT_UUID_BATTERY_VAL BT_UUID_128_ENCODE(0xc7839aa9, 0x1903, 0x40b5, 0xa8f0, 0x426e09ffb390)

#define BT_UUID_BASE    BT_UUID_DECLARE_128(BT_UUID_BASE_VAL)
#define BT_UUID_BATTERY BT_UUID_DECLARE_128(BT_UUID_BATTERY_VAL)

typedef int (*battery_cb_t)(void);

struct bt_app_cb {
	battery_cb_t battery_cb;
};

/** @brief Initialize the app_bt Service.
 *
 * @param[in] callbacks Struct containing pointers to callback functions
 *			used by the service. This pointer can be NULL
 *			if no callback functions are defined.
 *
 * @retval 0 If the operation was successful.
 *           Otherwise, a (negative) error code is returned.
 */
int bt_app_init(struct bt_app_cb *callbacks);

/** @brief Send the battery level.
 *
 * @param[in] battery_level The battery level to send.
 *
 * @retval 0 If the operation was successful.
 *           Otherwise, a (negative) error code is returned.
 */
int bt_app_send_battery_level(int battery_level);

/** @brief Start advertising.
 *
 * @retval 0 If the operation was successful.
 *           Otherwise, a (negative) error code is returned.
 */
int bt_app_advertise_start(void);

#endif