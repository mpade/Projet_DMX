-- phpMyAdmin SQL Dump
-- version 5.1.0
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost
-- Généré le : mer. 02 juin 2021 à 16:43
-- Version du serveur :  10.3.27-MariaDB-0+deb10u1
-- Version de PHP : 7.3.19-1~deb10u1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `Projet_DMX`
--

-- --------------------------------------------------------

--
-- Structure de la table `adressequipement`
--

CREATE TABLE `adressequipement` (
  `Id_AdressEquipement` int(11) NOT NULL,
  `Adresse` int(11) NOT NULL,
  `Id_Equipement` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `adressequipement`
--

INSERT INTO `adressequipement` (`Id_AdressEquipement`, `Adresse`, `Id_Equipement`) VALUES
(1, 20, 1),
(2, 35, 2),
(4, 102, 4);

-- --------------------------------------------------------

--
-- Structure de la table `equipement`
--

CREATE TABLE `equipement` (
  `Id_Equipement` int(11) NOT NULL,
  `Name` varchar(255) NOT NULL,
  `Nb_voie` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `equipement`
--

INSERT INTO `equipement` (`Id_Equipement`, `Name`, `Nb_voie`) VALUES
(1, 'Spot 10', 2),
(2, 'Spot 12', 1),
(4, 'Spot 5', 3);

-- --------------------------------------------------------

--
-- Structure de la table `manager`
--

CREATE TABLE `manager` (
  `Id_Manager` int(11) NOT NULL,
  `Programme` int(11) NOT NULL,
  `Scene` int(11) NOT NULL,
  `Id_Scene` int(11) NOT NULL,
  `Id_Programme` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `programme`
--

CREATE TABLE `programme` (
  `Id_Programme` int(11) NOT NULL,
  `Nom` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `property`
--

CREATE TABLE `property` (
  `Id_Property` int(11) NOT NULL,
  `Order` int(11) NOT NULL,
  `Description` varchar(255) NOT NULL,
  `Id_Equipement` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `property`
--

INSERT INTO `property` (`Id_Property`, `Order`, `Description`, `Id_Equipement`) VALUES
(1, 1, 'red', 1),
(2, 2, 'blue', 1),
(3, 1, 'red', 2),
(7, 1, 'red', 4),
(8, 2, 'green', 4),
(9, 3, 'blue', 4);

-- --------------------------------------------------------

--
-- Structure de la table `scene`
--

CREATE TABLE `scene` (
  `Id_Scene` int(11) NOT NULL,
  `Nom` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `scene`
--

INSERT INTO `scene` (`Id_Scene`, `Nom`) VALUES
(1, 'coucher de soleil'),
(2, 'lever de soleil'),
(3, 'scene1');

-- --------------------------------------------------------

--
-- Structure de la table `sceneprogramme`
--

CREATE TABLE `sceneprogramme` (
  `Id_SceneProgramme` int(11) NOT NULL,
  `Id_Scene` int(11) NOT NULL,
  `Id_Programme` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `sequence`
--

CREATE TABLE `sequence` (
  `Id_Sequence` int(11) NOT NULL,
  `Duree` int(11) NOT NULL,
  `name` varchar(25) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `sequence`
--

INSERT INTO `sequence` (`Id_Sequence`, `Duree`, `name`) VALUES
(20, 5, 'test_dernier'),
(21, 5, 'muhh'),
(22, 12, 'test'),
(23, 10, 'TEST'),
(24, 10, 'TEST'),
(25, 10, 'test');

-- --------------------------------------------------------

--
-- Structure de la table `sequencescene`
--

CREATE TABLE `sequencescene` (
  `Id_SequenceScene` int(11) NOT NULL,
  `Id_Sequence` int(11) NOT NULL,
  `Id_Scene` int(11) NOT NULL,
  `Order` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `sequenceusedequipement`
--

CREATE TABLE `sequenceusedequipement` (
  `Id_SequenceUsedEquipement` int(11) NOT NULL,
  `Id_AdressEquipement` int(11) NOT NULL,
  `Id_Sequence` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `sequenceusedequipement`
--

INSERT INTO `sequenceusedequipement` (`Id_SequenceUsedEquipement`, `Id_AdressEquipement`, `Id_Sequence`) VALUES
(18, 16, 20),
(19, 17, 21),
(20, 16, 22);

-- --------------------------------------------------------

--
-- Structure de la table `utilisateur`
--

CREATE TABLE `utilisateur` (
  `Id_Utilisateur` int(11) NOT NULL,
  `Nom` varchar(255) NOT NULL,
  `Prenom` varchar(255) NOT NULL,
  `Email` varchar(255) NOT NULL,
  `MotDePasse` varchar(255) NOT NULL,
  `Grade` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `utilisateur`
--

INSERT INTO `utilisateur` (`Id_Utilisateur`, `Nom`, `Prenom`, `Email`, `MotDePasse`, `Grade`) VALUES
(1, 'marco', 'marco', 'mpade@la-providence.net', 'Pade', 0);

-- --------------------------------------------------------

--
-- Structure de la table `valueproper`
--

CREATE TABLE `valueproper` (
  `value` int(11) NOT NULL,
  `id_property` int(11) NOT NULL,
  `id_sequence` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `valueproper`
--

INSERT INTO `valueproper` (`value`, `id_property`, `id_sequence`) VALUES
(63, 20, 20),
(140, 21, 20),
(0, 22, 20),
(0, 23, 20),
(157, 24, 21),
(0, 25, 21),
(255, 26, 21),
(0, 27, 21),
(108, 20, 22),
(168, 21, 22),
(77, 22, 22),
(112, 23, 22);

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `adressequipement`
--
ALTER TABLE `adressequipement`
  ADD PRIMARY KEY (`Id_AdressEquipement`),
  ADD KEY `Id_Equipement` (`Id_Equipement`);

--
-- Index pour la table `equipement`
--
ALTER TABLE `equipement`
  ADD PRIMARY KEY (`Id_Equipement`);

--
-- Index pour la table `manager`
--
ALTER TABLE `manager`
  ADD PRIMARY KEY (`Id_Manager`);

--
-- Index pour la table `programme`
--
ALTER TABLE `programme`
  ADD PRIMARY KEY (`Id_Programme`);

--
-- Index pour la table `property`
--
ALTER TABLE `property`
  ADD PRIMARY KEY (`Id_Property`),
  ADD KEY `Id_Equipement` (`Id_Equipement`);

--
-- Index pour la table `scene`
--
ALTER TABLE `scene`
  ADD PRIMARY KEY (`Id_Scene`);

--
-- Index pour la table `sceneprogramme`
--
ALTER TABLE `sceneprogramme`
  ADD PRIMARY KEY (`Id_SceneProgramme`),
  ADD KEY `Id_Programme` (`Id_Programme`);

--
-- Index pour la table `sequence`
--
ALTER TABLE `sequence`
  ADD PRIMARY KEY (`Id_Sequence`);

--
-- Index pour la table `sequencescene`
--
ALTER TABLE `sequencescene`
  ADD PRIMARY KEY (`Id_SequenceScene`),
  ADD KEY `Id_Scene` (`Id_Scene`);

--
-- Index pour la table `sequenceusedequipement`
--
ALTER TABLE `sequenceusedequipement`
  ADD PRIMARY KEY (`Id_SequenceUsedEquipement`),
  ADD KEY `Id_AdressEquipement` (`Id_AdressEquipement`),
  ADD KEY `Id_Sequence` (`Id_Sequence`);

--
-- Index pour la table `utilisateur`
--
ALTER TABLE `utilisateur`
  ADD PRIMARY KEY (`Id_Utilisateur`);

--
-- Index pour la table `valueproper`
--
ALTER TABLE `valueproper`
  ADD KEY `id_property` (`id_property`),
  ADD KEY `id_sequence` (`id_sequence`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `adressequipement`
--
ALTER TABLE `adressequipement`
  MODIFY `Id_AdressEquipement` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT pour la table `equipement`
--
ALTER TABLE `equipement`
  MODIFY `Id_Equipement` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT pour la table `manager`
--
ALTER TABLE `manager`
  MODIFY `Id_Manager` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `programme`
--
ALTER TABLE `programme`
  MODIFY `Id_Programme` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;

--
-- AUTO_INCREMENT pour la table `property`
--
ALTER TABLE `property`
  MODIFY `Id_Property` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT pour la table `scene`
--
ALTER TABLE `scene`
  MODIFY `Id_Scene` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pour la table `sceneprogramme`
--
ALTER TABLE `sceneprogramme`
  MODIFY `Id_SceneProgramme` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=39;

--
-- AUTO_INCREMENT pour la table `sequence`
--
ALTER TABLE `sequence`
  MODIFY `Id_Sequence` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=26;

--
-- AUTO_INCREMENT pour la table `sequencescene`
--
ALTER TABLE `sequencescene`
  MODIFY `Id_SequenceScene` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT pour la table `sequenceusedequipement`
--
ALTER TABLE `sequenceusedequipement`
  MODIFY `Id_SequenceUsedEquipement` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=21;

--
-- AUTO_INCREMENT pour la table `utilisateur`
--
ALTER TABLE `utilisateur`
  MODIFY `Id_Utilisateur` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
