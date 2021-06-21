def calculate_bms_statistics(bms_data):
    temperature_values = []
    soc_values = []
    final_display_list = {}
    if len(bms_data) < 5:
        return False
    for i in range(-5, 0, 1):
        temperature_values.append(float(bms_data[i][0][1]))
        soc_values.append(float(bms_data[i][1][1]))

    soc_values.sort()
    temperature_values.sort()
    final_display_list['temperature'] = temperature_values
    final_display_list['soc'] = soc_values
    return  final_display_list

def format_bms_data(bms_details):
    bms_details = bms_details.replace('Temp','Temperature')
    bms_details = bms_details.replace('and', ',')
    bms_details = bms_details.replace('value is', '=')
    bms_details = bms_details.replace(' ', '')
    bms_details = bms_details.split(',')
    bms_details[0] = bms_details[0].split('=')
    bms_details[1] = bms_details[1].split('=')
    return bms_details

def average(list):
    return round(sum(list) / len(list), 2)
