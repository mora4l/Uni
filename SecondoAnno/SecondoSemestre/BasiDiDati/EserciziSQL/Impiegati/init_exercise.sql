-- drop table SEDI_DIP;
-- drop table LAVORA_SU;
-- drop table PROGETTO;
-- drop table IMPIEGATO;
-- drop table DIPARTIMENTO;

create table DIPARTIMENTO(nome text not null, 
                            id_dipartimento int not null, 
                            primary key(id_dipartimento));

create table IMPIEGATO(nome text not null, 
                        cognome text not null, 
                        id_impiegato int not null,
                        inizio date not null, 
                        id_dipartimento int not null, 
                        id_superiore int,
                        dirige_dipartimento int,
                        primary key(id_impiegato),
                        foreign key(id_superiore) references IMPIEGATO(id_impiegato),
                        foreign key(id_dipartimento) references DIPARTIMENTO(id_dipartimento),
                        foreign key(dirige_dipartimento) references DIPARTIMENTO(id_dipartimento)
                        );

create table PROGETTO(nome text not null, 
                        id_progetto int not null, 
                        id_dipartimento int not null, 
                        primary key(id_progetto),
                        foreign key(id_dipartimento) references DIPARTIMENTO(id_dipartimento)
                        );

create table SEDI_DIP(id_dipartimento int not null, 
                nome text not null, 
                primary key(id_dipartimento, nome)
                foreign key(id_dipartimento) references DIPARTIMENTO(id_dipartimento)
                );

create TABLE LAVORA_SU(id_progetto int not null, 
                        id_impiegato int not null, 
                        ore int not null, 
                        primary key(id_progetto, id_impiegato),
                        foreign key(id_progetto) references PROGETTO(id_progetto),
                        foreign key(id_impiegato) references IMPIEGATO(id_impiegato)
                        );


-- Dipartimenti

insert into DIPARTIMENTO values ("D0", 0);
insert into DIPARTIMENTO values ("D1", 1);
insert into DIPARTIMENTO values ("D2", 2);

-- Impiegati

insert into IMPIEGATO values ("Mario", "Rossi", 0, "2020-01-01", 0, null, 0);
insert into IMPIEGATO values ("Maria", "Arancioni", 1, "2020-01-01", 1, null, 1);
insert into IMPIEGATO values ("Ethan", "Smith", 2, "2020-01-01", 2, null, 2);

insert into IMPIEGATO values ("John", "Snow", 3, "2020-05-01", 0, 0, null);
insert into IMPIEGATO values ("J.J.", "Abrams", 4, "2020-03-01", 1, 1, null);
insert into IMPIEGATO values ("Alma", "Palmer", 5, "2020-02-01", 2, 2, null);

insert into IMPIEGATO values ("Kaith", "Sith", 6, "2020-06-01", 0, 0, null);
insert into IMPIEGATO values ("Ethan", "Kuranaga", 7, "2020-02-01", 1, 1, null);
insert into IMPIEGATO values ("Sora", "Kisanagi", 8, "2020-08-01", 2, 2, null);

-- Progetti

insert into PROGETTO values ("VBA 1.0", 0, 0);
insert into PROGETTO values ("VBA 2.0", 1, 0);
insert into PROGETTO values ("New Science Frontiers", 2, 1);
insert into PROGETTO values ("Notflix", 3, 2);
insert into PROGETTO values ("Book shipping", 4, 2);

-- Sedi Dipartimento

insert into SEDI_DIP values (0, "Bolzaneto");
insert into SEDI_DIP values (0, "Florida");
insert into SEDI_DIP values (0, "Tokyo");
insert into SEDI_DIP values (1, "Firenze");
insert into SEDI_DIP values (2, "Roma");

-- Lavora Su

insert into LAVORA_SU values (0, 0, 10);
insert into LAVORA_SU values (1, 0, 9);
insert into LAVORA_SU values (0, 3, 1);
insert into LAVORA_SU values (1, 6, 5);

insert into LAVORA_SU values (2, 1, 10);
insert into LAVORA_SU values (2, 4, 10);
insert into LAVORA_SU values (2, 7, 10);

insert into LAVORA_SU values (3, 2, 7);
insert into LAVORA_SU values (3, 5, 7);
insert into LAVORA_SU values (3, 8, 3);
insert into LAVORA_SU values (4, 8, 15);


-- DROP TABLE LAVORA_SU;

-- CREATE TABLE LAVORA_SU (
--     id_progetto  INT NOT NULL,
--     id_impiegato INT NOT NULL,
--     ore          INT NOT NULL,
--     PRIMARY KEY (
--         id_progetto,
--         id_impiegato
--     ),
--     FOREIGN KEY (
--         id_progetto
--     )
--     REFERENCES PROGETTO (id_progetto),
--     FOREIGN KEY (
--         id_impiegato
--     )
--     REFERENCES IMPIEGATO (id_impiegato) ON DELETE CASCADE
-- );

-- insert into LAVORA_SU values (0, 0, 10);
-- insert into LAVORA_SU values (1, 0, 9);
-- insert into LAVORA_SU values (0, 3, 1);
-- insert into LAVORA_SU values (1, 6, 5);

-- insert into LAVORA_SU values (2, 1, 10);
-- insert into LAVORA_SU values (2, 4, 10);
-- insert into LAVORA_SU values (2, 7, 10);

-- insert into LAVORA_SU values (3, 2, 7);
-- insert into LAVORA_SU values (3, 5, 7);
-- insert into LAVORA_SU values (3, 8, 3);
-- insert into LAVORA_SU values (4, 8, 15);

-- insert into LAVORA_SU values (2, 9, 8);

-- delete from impiegato where id_impiegato=9;