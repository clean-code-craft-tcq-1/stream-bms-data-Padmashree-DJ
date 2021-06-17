
def recevie_bms_details():
    final_bms_data = []
    while(True):
        bms_details = input()
        bms_details = format_bms_data(bms_details)
        final_bms_data.append(bms_details)
        if len(final_bms_data) >= 5:
            calculate_bms_statistics(final_bms_data)

def calculate_bms_statistics(bms_data):
    temperature_values = []
    soc_values = []
    final_display_list = {}

    for i in range(-5, 0, 1):
        temperature_values.append(float(bms_data[i][0][1]))
        soc_values.append(float(bms_data[i][1][1]))

    soc_values.sort()
    temperature_values.sort()
    final_display_list['temperature'] = temperature_values
    final_display_list['soc'] = soc_values
    display_bms_statistics(final_display_list)
    
def display_bms_statistics(bms_data):
    print('Max Temperature:', bms_data['temperature'][-1])
    print('Min Temperature:', bms_data['temperature'][0])
    print('Average Temperature:', average(bms_data['temperature']))
    print('Max SOC:', bms_data['soc'][-1])
    print('Min SOC:', bms_data['soc'][0])
    print('Average SOC:', average(bms_data['soc']))



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


recevie_bms_details()
