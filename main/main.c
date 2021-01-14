#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "nvs_flash.h"
#include "esp_log.h"

static const char *TAG = "app_main";

void app_main(void)
{
    esp_log_level_set(TAG, ESP_LOG_VERBOSE);
    ESP_LOGI(TAG, "Running at %s:%d", __FILE__, __LINE__);
    
    uint16_t initial_tasks = uxTaskGetNumberOfTasks();
    ESP_LOGI(TAG, "Number of running tasks: %d", initial_tasks);

    //Initialize NVS --- 
    esp_err_t ret = nvs_flash_init();
    if(ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);


}
