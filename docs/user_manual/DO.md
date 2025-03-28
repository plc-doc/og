# Модуль дискретного вывода IPCSA-OG-DO

## Общие сведения

??? example "Тестирование"

    На текущий момент модуль на стадии тестирования. Серийный выпуск запланирован на декабрь 2025 года 

<div class="grid cards" markdown>

![Image title](../img/modules/DO.png){ width="150" align=left  }
Модуль дискретных выходов DO (арт. IPCSA-OG-DO) является 16-ти канальным модулем расширения и предназначен для вывода дискретных команд постоянным напряжением 24 В.
Модуль оснащен отдельной клеммой, обеспечивающей защиту от воздействия ЭДС самоиндукции при подключении к нему индуктивной нагрузки (электромагнитные реле и т.п.).

</div>

## Технические характеристики 
| Характеристика                          | Значение                     |
|-----------------------------------------|------------------------------|
| Максимальная потребляемая мощность, Вт | 3                            |
| Количество выходных каналов            | 16                           |
| Номинальное выходное напряжение, В     | 24                           |
| Максимальный ток логической единицы, мА/канал | 140                  |
| Ток логического нуля (утечки), мкА     | 25                           |
| Гальваническая изоляция                | Между входной и выходной логикой |

| Сечение проводника, мм²                | От 0,2 до 1,5                |
| Масса, г                               | 125                          |
| Габариты ВхШхГ, мм                     | 126х21,3х90                  |

## Эксплуатационные характеристики
| Характеристика                   | Значение           |
| -------------------------------- | -                  |
| Температура эксплуатации, °С     | От минус 40 до 60  |
| Температура хранения, °С         | От минус 40 до 60  |
| Влажность при хранении, %	       | От 5 до 95         |
| Влажность при эксплуатации, %    | От 5 до 95         |
| Тип монтажа                      | На DIN-рейку 35 мм |
| Расположение при монтаже         | Вертикальное       |

## Схема подключения

<div class="grid cards" markdown>
![Image title](../img/connection/DO.svg){ width="370"; align=left  }

![Image title](../img/connection/connector_18pin.png){ width="170";  }
</div>

| Обозначение | Название канала | Описание                       |
|-------------|-----------------|--------------------------------|
| 1 - 16      | DO1 - OD16      | Выходной канал 1 - 16          |
| 17          | GND             | Общий контакт                  |
| 18          | PCOM            | Защита от индуктивной нагрузки |

## Индикация
| Обозначение | Индикация | Показатель |
|------------------|----------------------|---------------------------------------|
| P | :green_circle:| Наличие напряжения питания |
| P | :white_circle:| Отсутствие напряжения питания |
| L | :green_circle:| Наличие соединения Ethernet |
| L | :yellow_circle: :green_circle: :yellow_circle: | Обмен данными по Ethernet |
| L | :white_circle:| Отсутствие соединения Ethernet|
| 1-16 | :green_circle:| Контакт «1», «2», ..., «16» замкнут  |
| 1-16 | :white_circle:| Контакт «1», «2», ..., «16» разомнут|

## Размеры

=== "Габаритные размеры" 
    ![Image title](../img/dimensions/overall_dimensions_extensions.png){ width="580"}
=== "Установочные размеры"
    ![alt text](../img/dimensions/installation_dimensions.png) 

## 3D-модель
<model-viewer src="https://xn--j1abl.online//img/3d/DI.glb"
alt="3D Model"
auto-rotate
camera-controls
poster="https://xn--j1abl.online//img/3d/posterDI.webp"
camera-orbit="160deg 75deg 348m"
field-of-view="30deg"
exposure="0.5"
style="width: 100%; height: 500px;">
</model-viewer>


## Программное обеспечение
Актуальный конфигурационный файл можно скачать по 
<a href="../../downloads/IPCSA_OG.xml" download>ссылке</a>


### Информация PDO модуля на языке C

``` dtd title="PDO"
    SM0: PhysAddr 0x0f00, DefaultSize    0, ControlRegister 0x44, Enable 9
  RxPDO 0x1a00 "Byte 0"
    PDO entry 0x3101:01,  8 bit, "Output" <!--(1)!-->
  RxPDO 0x1a01 "Byte 0"
    PDO entry 0x3101:02,  8 bit, "Output"
SM1: PhysAddr 0x0f01, DefaultSize    0, ControlRegister 0x44, Enable 9
```

1. Состояние каждого входа управляется соотвествующим битом. Например: 0b00000001 - замкнут контакт 1, 0b00000010 - замкнут контакт 2 и т. д.

``` c title="Ethercat cstruct"
/* Master 0, Slave 0, "IPCSA-OG-DIGITAL-OUTPUT"
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
``` 


