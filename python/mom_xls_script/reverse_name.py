from openpyxl import load_workbook

def count_spaces(name: str) -> int:
    if name == None:
        return -1
    return len(name.split(' '))

def return_outliers(xls_cell):
    with count_spaces(xls_cell.value) as spaces:
        if spaces != 2:
            print(xls_cell)





wb = load_workbook(filename='/home/tw/Downloads/apoderados.xlsx')
students = wb['alumnos']
#[print(count_spaces(x[0].value)) for x in students['A3:A438']]

def quizas_fix(name) -> str:
    if name[0].value is None:
        return "Noneee"
    else:
        mysplit = x[0].value.split(' ')
        if len(mysplit) == 1:
            return mysplit[0]
        elif len(mysplit) == 3:
            if mysplit[2] == '':
                return ' '.join([mysplit[1], mysplit[0]])
            else:
                return ' '.join([mysplit[2], mysplit[0], mysplit[1]])
        else:
            return ' '.join([mysplit[1], mysplit[0]])

    return "qwea?", x[0].value



for x in students['A3':'A438']:
    if x[0].value is not None:
        if len(x[0].value.split()) != 2:
            print(quizas_fix(x))
    # if x[0].value is None:
    #     print("Noneee")
    # else:
    #     mysplit = x[0].value.split(' ')
    #     if len(mysplit) == 1:
    #         print(mysplit[0], "<- No cambia")
    #     elif len(mysplit) == 3:
    #         if mysplit[2] == '':
    #             print(mysplit[0], mysplit[1], "<------ aer?")
    #         else:
    #             print(mysplit[2], mysplit[0], mysplit[1], "<------ aer?")

#wb.save('/home/tw/Downloads/apoderados_fixed.xlsx')