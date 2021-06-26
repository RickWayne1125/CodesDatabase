import PyInquirer
import tabulate
import config

from typing import Callable, Dict, List

import pymysql
pymysql.install_as_MySQLdb()
import MySQLdb


def __choice_to_function(message: str,
                         choices: Dict[str, Callable[[MySQLdb.Connection], bool]], db: MySQLdb.Connection) -> bool:
    return choices[PyInquirer.prompt([{
        'type': 'list', 'name': 'op', 'message': message, 'choices': list(choices.keys())
    }])['op']](db)


def __not_null(v: str):
    return len(v) != 0


def __query(db: MySQLdb.Connection, table: str, args: Dict[str, str], headers: List[str]):
    cond = [k for k in args.keys() if len(args[k]) != 0]
    stmt = 'SELECT * FROM ' + table
    if len(cond) != 0:
        stmt += ' WHERE ' + ' AND '.join([k + ' = %s' for k in cond])
    cs = db.cursor()
    cs.execute(stmt, tuple([args[k] for k in cond]))
    print()
    print(tabulate.tabulate(cs.fetchall(), headers=headers, tablefmt='pretty'))
    print()
    cs.close()


def __create(db: MySQLdb.Connection, table: str, args: Dict[str, str]):
    cols = list(args.keys())
    stmt = 'INSERT INTO ' + table + \
        ' (' + ', '.join(cols) + ') VALUES (' + \
           ', '.join(['%s'] * len(cols)) + ')'
    cs = db.cursor()
    cs.execute(stmt, tuple([args[k] for k in cols]))
    print()
    cs.close()


def __remove(db: MySQLdb.Connection, table: str, args: Dict[str, str]):
    cond = [k for k in args.keys() if len(args[k]) != 0]
    if len(cond) != 0:
        stmt = ' WHERE ' + ' AND '.join([k + ' = %s' for k in cond])
    else:
        stmt = ''
    cs = db.cursor()
    cs.execute('SELECT COUNT(*) FROM ' + table +
               stmt, tuple([args[k] for k in cond]))
    nm = cs.fetchone()[0]
    if nm == 0:
        print('Nothing to do')
    else:
        if PyInquirer.prompt(
                {
                    'type': 'confirm',
                    'name': 'confirm',
                    'message': '%d rows about to be removed, continue?' % nm,
                    'default': False
                })['confirm']:
            cs.execute('DELETE FROM ' + table + stmt,
                       tuple([args[k] for k in cond]))
            db.commit()
        else:
            print('Aborted')
    print()
    cs.close()


__filter_rule = [{
    'type': 'input', 'name': 'RName', 'message': 'Filter Rule Name:'
}, {
    'type': 'input', 'name': 'RID', 'message': 'Filter Rule ID:'
}, {
    'type': 'input', 'name': 'FaID', 'message': 'Filter Fact ID:'
}]

__filter_feature = [{
    'type': 'input', 'name': 'FeID', 'message': 'Filter Feature ID:'
}, {
    'type': 'input', 'name': 'Attr', 'message': 'Filter Feature Attribute'
}, {
    'type': 'input', 'name': 'OP', 'message': 'Filter Feature Operator'
}, {
    'type': 'input', 'name': 'FeValue', 'message': 'Filter Feature Value:'
}]

__filter_fact = [{
    'type': 'input', 'name': 'FaID', 'message': 'Filter Fact ID:'
}, {
    'type': 'input', 'name': 'Attr', 'message': 'Filter Fact Attribute:'
}, {
    'type': 'input', 'name': 'OP', 'message': 'Filter Fact Operator:'
}, {
    'type': 'input', 'name': 'FaValue', 'message': 'Filter Fact Value:'
}]

__filter_feature_rule = [{
    'type': 'input', 'name': 'FRID', 'message': 'Filter Feature-Rule ID:'
}, {
    'type': 'input', 'name': 'RID', 'message': 'Filter Rule ID:'
}, {
    'type': 'input', 'name': 'FeID', 'message': 'Filter Feature ID:'
}]

# __enter_rule = [{
#     'type': 'input', 'name': 'RULE', 'message': 'Please enter the new rule in format ({Attr OP Value}, ..., {Attr OP Value} -> {Attr OP Value}):', 'validate': __not_null
# }]
__enter_rule = [{
    # 'type': 'input', 'name': 'RID', 'message': 'RID:', 'validate': __not_null,
    'type': 'input', 'name': 'RName', 'message': 'Name:', 'validate': __not_null
}, {
    'type': 'input', 'name': 'FaID', 'message': 'FaID:', 'validate': __not_null
}]

__enter_fact = [{
    # 'type': 'input', 'name': 'FaID', 'message': 'FaID:', 'validate': __not_null,
    'type': 'input', 'name': 'Attr', 'message': 'Attribute:', 'validate': __not_null
}, {
    'type': 'input', 'name': 'OP', 'message': 'Operator:', 'validate': __not_null
}, {
    'type': 'input', 'name': 'FaValue', 'message': 'FaValue:', 'validate': __not_null
}]

__enter_feature = [{
    # 'type': 'input', 'name': 'FaID', 'message': 'FaID:', 'validate': __not_null,
    'type': 'input', 'name': 'Attr', 'message': 'Attribute:', 'validate': __not_null
}, {
    'type': 'input', 'name': 'OP', 'message': 'Operator:', 'validate': __not_null
}, {
    'type': 'input', 'name': 'FeValue', 'message': 'FeValue:', 'validate': __not_null
}]

__enter_feature_rule = [{
    # 'type': 'input', 'name': 'FaID', 'message': 'FaID:', 'validate': __not_null,
    'type': 'input', 'name': 'RID', 'message': 'RID:', 'validate': __not_null
}, {
    'type': 'input', 'name': 'FeID', 'message': 'FeID:', 'validate': __not_null
}]


def query_rules(db: MySQLdb.Connection) -> bool:
    __query(db, 'Rule', PyInquirer.prompt(
        __filter_rule), ['RID', 'RName', 'FaID'])
    return True


def query_features(db: MySQLdb.Connection) -> bool:
    __query(db, 'Feature', PyInquirer.prompt(__filter_feature),
            ['FeID', 'Attr', 'OP', 'FeValue'])
    return True


def query_facts(db: MySQLdb.Connection) -> bool:
    __query(db, 'Fact', PyInquirer.prompt(__filter_fact),
            ['FaID', 'Attr', 'OP', 'FaValue'])
    return True


def query_features_rules(db: MySQLdb.Connection) -> bool:
    __query(db, 'FeatureRule', PyInquirer.prompt(__filter_feature_rule),
            ['FRID', 'RID', 'FeID'])
    return True


def create_rule(db: MySQLdb.Connection) -> bool:
    __create(db, 'Rule', PyInquirer.prompt(__enter_rule))
    return True


def create_fact(db: MySQLdb.Connection) -> bool:
    __create(db, 'Fact', PyInquirer.prompt(__enter_fact))
    return True


def create_feature(db: MySQLdb.Connection) -> bool:
    __create(db, 'Feature', PyInquirer.prompt(__enter_feature))
    return True


def create_feature_rule(db: MySQLdb.Connection) -> bool:
    __create(db, 'FeatureRule', PyInquirer.prompt(__enter_feature_rule))
    return True


def main():
    db = MySQLdb.connect(host=config.DB['host'],
                         port=config.DB['port'],
                         user=config.DB['user'], passwd=config.DB['pass'], db=config.DB['name'])
    cs = db.cursor()
    cs.execute('CREATE TABLE IF NOT EXISTS Fact ('
               'FaID int(8) primary key auto_increment not null,'
               'Attr varchar(30) not null,'
               'OP varchar(30) not null,'
               'FaValue varchar(30) not null)')
    cs.execute('CREATE TABLE IF NOT EXISTS Rule ('
               'RID int(8) primary key auto_increment not null,'
               'RName varchar(30) not null,'
               'FaID int(8) not null,'
               'foreign key(FaID) references Fact(FaID))')
    cs.execute('CREATE TABLE IF NOT EXISTS Feature ('
               'FeID int(8) primary key auto_increment not null,'
               'Attr varchar(30) not null,'
               'OP varchar(30) not null,'
               'FeValue varchar(30) not null)')
    cs.execute('CREATE TABLE IF NOT EXISTS FeatureRule ('
               'FRID int(8) primary key auto_increment not null,'
               'RID int(8) not null,'
               'FeID int(8) not null,'
               'foreign key(RID) references Rule(RID),'
               'foreign key(FeID) references Feature(FeID))')
    cs.execute('CREATE TABLE IF NOT EXISTS MatchHistory ('
               'HID int(8) primary key auto_increment not null,'
               'StateBool boolean not null,'
               'RID int(8) not null,'
               'foreign key(RID) references Rule(RID))')
    db.commit()
    cs.close()

    while __choice_to_function('Select your operation:',
                               {
                                   'Query Rules': query_rules,
                                   'Query Features': query_features,
                                   'Query Facts': query_facts,
                                   'Query Feature-Rules': query_features_rules,
                                   'Create Fact': create_fact,
                                   'Create Feature': create_feature,
                                   'Create Rule': create_rule,
                                   'Create Feature-Rule': create_feature_rule,
                                   'Quit': lambda _: False
                               }, db):
        pass

    db.close()


if __name__ == '__main__':
    main()
