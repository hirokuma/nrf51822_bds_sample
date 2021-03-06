/* This file was generated by plugin 'Nordic Semiconductor nRF5x v.1.1.6' (BDS version 1.0.1531.0) */

#include "service_if.h"
#include <stdint.h>
#include "app_trace.h" 
#include "ble_ios.h" 

static ble_ios_t    m_ios; 



/**@brief Function for handling the ios events.
 *
 * @details This function will be called for all ios events which are passed to
 *          the application.
 *
 * @param[in]   p_ios   ios structure.
 * @param[in]   p_evt   Event received from the ios.
 */
static void on_ios_evt(ble_ios_t * p_ios, ble_ios_evt_t * p_evt)
{
    switch (p_evt->evt_type)
    { 
        case BLE_IOS_INPUT_EVT_WRITE:
            app_trace_log("[Bluetooth_IF]: IOS_INPUT evt WRITE. \r\n");
            break; 
        case BLE_IOS_OUTPUT_EVT_NOTIFICATION_ENABLED:
            app_trace_log("[Bluetooth_IF]: IOS_OUTPUT evt NOTIFICATION_ENABLED. \r\n");
            break;
        case BLE_IOS_OUTPUT_EVT_NOTIFICATION_DISABLED:
            app_trace_log("[Bluetooth_IF]: IOS_OUTPUT evt NOTIFICATION_DISABLED. \r\n");
            break;
        case BLE_IOS_OUTPUT_EVT_CCCD_WRITE:
            app_trace_log("[Bluetooth_IF]: IOS_OUTPUT evt CCCD_WRITE. \r\n");
            break; 
        default:
            // No implementation needed.
            break;
    }
}


/**@brief Function for initializing the Services generated by Bluetooth Developer Studio.
 *
 *
 * @return      NRF_SUCCESS on successful initialization of services, otherwise an error code.
 */
uint32_t bluetooth_init(void)
{
    uint32_t    err_code; 
    ble_ios_init_t    ios_init; 
    

    // Initialize ios.
    memset(&ios_init, 0, sizeof(ios_init));

    ios_init.evt_handler = on_ios_evt; 
    ios_init.ble_ios_input_initial_value.value = 0x0; 
    ios_init.ble_ios_output_initial_value.value = 0x0; 

    err_code = ble_ios_init(&m_ios, &ios_init);
    if (err_code != NRF_SUCCESS)
    {
        return err_code;
    } 

    return NRF_SUCCESS;
}

/**@brief Function for handling the Application's BLE Stack events.
 *
 * @details Handles all events from the BLE stack of interest to all Bluetooth Developer Studio generated Services.
 *
 * @param[in]   p_ble_evt  Event received from the BLE stack.
 */
void bluetooth_on_ble_evt(ble_evt_t * p_ble_evt)
{ 
    ble_ios_on_ble_evt(&m_ios, p_ble_evt); 
}
